#pragma once
#include "HotDrink.h"

// Abstract Factory called `HotDrinkFactory`
class HotDrinkFactory
{
  public:
    // Defines a pure virtual function `make()` that returns a unique pointer to a `HotDrink` object
    virtual std::unique_ptr<HotDrink> make() const = 0;
};

// Concrete factory for creating Tea objects
class TeaFactory : public HotDrinkFactory
{
  public:
    // Overrides the `make()` function from the `HotDrinkFactory` class
    std::unique_ptr<HotDrink> make() const
    {
        // Create and return a unique pointer to a Tea object
        return std::make_unique<Tea>();
    }
};

class CoffeeFactory : public HotDrinkFactory
{
  public:
    // Overrides the `make()` function from the `HotDrinkFactory` class
    std::unique_ptr<HotDrink> make() const
    {
        // Create and return a unique pointer to a Coffee object
        return std::make_unique<Coffee>();
    }
};