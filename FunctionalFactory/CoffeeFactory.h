#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include <memory>

struct CoffeeFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Coffee>();
    }
};