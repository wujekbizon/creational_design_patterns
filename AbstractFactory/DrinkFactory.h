#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include <map>
#include <string>

class DrinkFactory
{
    // Define a map to store hot drink factories
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotFactories;

  public:
    // Constructor to initialize the map of hot drink factories
    DrinkFactory()
    {
        hotFactories["coffee"] = std::make_unique<CoffeeFactory>();
        hotFactories["tea"] = std::make_unique<TeaFactory>();
    }

    // Function to create a hot drink based on the provided name
    std::unique_ptr<HotDrink> makeDrink(const std::string &name)
    {
        // Get the corresponding hot drink factory from the map
        const auto &hotDrinkFactory = hotFactories.find(name); // Find the factory associated with the "name"

        // Check if the factory exists for the requested drink type
        if (hotDrinkFactory == hotFactories.end())
        { // If the factory is not found for the "name"
            // Throw an exception if the factory is not found
            throw std::runtime_error("Invalid drink type: " +
                                     name); // Throw an error indicating that the "name" is not a valid drink type
        }

        // Create a hot drink object using the factory's make() function
        auto drink = hotFactories[name]->make();
        // Prepare the created hot drink object, which will trigger a memory leak
        drink->prepare(200); // This line calls the `prepare()` method on the `drink` object, which would cause a memory
                             // leak if left unaddressed.

        /*
           fixed the memory leak by using the std::move() method. By moving ownership of the drink object to the caller,
           we ensure that the caller will be responsible for calling its destructor and releasing the associated memory.
           This prevents the memory leak from occurring.
           */
        return std::move(drink); // This line returns the newly created `HotDrink` object to the caller, effectively
                                 // transferring ownership to them.
    }
};
