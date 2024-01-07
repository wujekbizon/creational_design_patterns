#pragma once
#include "CoffeeFactory.h"
#include "HotDrink.h"
#include "TeaFactory.h"
#include <functional>
#include <map>
#include <string>

struct HotDrink;

class DrinkFactory
{
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotFactories;

  public:
    DrinkFactory()
    {

        hotFactories["coffee"] = std::make_unique<CoffeeFactory>();

        hotFactories["tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<HotDrink> makeDrink(const std::string &name)
    {
        auto drink = hotFactories[name]->make();
        drink->prepare(200); // oops!
        return drink;
    }
};

// This class represents a factory for creating hot drinks with a specific volume.
class DrinkWithVolumeFactory
{
    std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

  public:
    // Constructor to initialize the map of drink factories
    DrinkWithVolumeFactory()
    {
        // Create lambda expressions for creating `Tea` and `Coffee` objects with the specified volume
        factories["tea"] = [] {
            auto tea = std::make_unique<Tea>(); // Create a unique pointer to a `Tea` object
            tea->prepare(200);                  // Prepare the `Tea` object with the specified volume
            return tea;
        };

        factories["coffee"] = [] {
            auto coffee = std::make_unique<Coffee>(); // Create a unique pointer to a `Coffee` object
            coffee->prepare(200);                     // Prepare the `Coffee` object with the specified volume
            return coffee;
        };
    }

    // Function to create a hot drink based on the provided name
    std::unique_ptr<HotDrink> makeDrink(const std::string &name);
};

// Inline specifier for the `makeDrink()` function
inline std::unique_ptr<HotDrink> DrinkWithVolumeFactory::makeDrink(const std::string &name)
{
    // Check if the specified drink type exists in the factory map
    if (factories.count(name) == 0)
    {
        // Throw an exception if the provided drink type is not found
        throw std::out_of_range("Invalid drink type");
    }

    // Create the hot drink object using the corresponding lambda expression
    return factories[name]();
}