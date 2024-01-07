#include "DrinkFactory.h"
#include <iostream>
#include <map>
#include <memory>

/*
This `makeDrink()` function is used to create hot drinks based on their names.
It's not a recommended practice because it couples the creation of hot drinks directly
to their names, making it difficult to extend or modify the code.
Is not type-safe, as it directly creates instances of `Tea` and `Coffee` objects without any checks or validation.
Is tightly coupled to the `HotDrink` classes, making it difficult to reuse or replace
them with different hot drink implementations.
and violates the principle of encapsulation, as it directly exposes the creation of hot drink objects to the client
code.
*/
// method that will make drink depending on the name of the drink.
std::unique_ptr<HotDrink> makeDrink(std::string_view type)
{
    // Create a unique pointer to store the hot drink object
    std::unique_ptr<HotDrink> drink;

    // Check the provided drink type
    if (type == "tea")
    {
        // Create a unique pointer to a `Tea` object
        drink = std::make_unique<Tea>();
        // Prepare the hot drink object
        drink->prepare(200);
    }
    else
    {
        // Create a unique pointer to a `Coffee` object
        drink = std::make_unique<Coffee>();
        // Prepare the hot drink object
        drink->prepare(50);
    }

    // Return the newly created hot drink object
    return drink;
}

int main()
{
    // Instead of using the `makeDrink()` function, which is not recommended, we can use the `DrinkFactory` to create
    // hot drinks. This is a more flexible and maintainable approach.
    // auto d = makeDrink("cofee");
    // auto d2 = makeDrink("tea");

    // Create a `DrinkFactory` instance
    DrinkFactory df;

    // Create a hot drink using the `DrinkFactory`
    auto c = df.makeDrink("coffee");
    return 0;
}