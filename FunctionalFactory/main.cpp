#include "DrinkFactory.h"
#include "HotDrinkFactory.h"
#include <iostream>
#include <map>
#include <memory>

int main()
{
    DrinkWithVolumeFactory df;
    auto coffee = df.makeDrink("coffee");
    return 0;
}