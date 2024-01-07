#pragma once
#include "HotDrink.h"

// Abstract Factory called `HotDrinkFactory`
class HotDrinkFactory
{
  public:
    virtual std::unique_ptr<HotDrink> make() const = 0;
};
