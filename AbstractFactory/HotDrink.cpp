#include "HotDrink.h"

void Tea::prepare(const int &volume)
{
    // This is the implementation of the prepare() function
    // for Tea. It will be called when a Tea object is passed to
    // the prepare() function of a HotDrink object.
    std::cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon\n";
}

void Coffee::prepare(const int &volume)
{
    // This is the implementation of the prepare() function
    // for Coffee. It will be called when a Coffee object is passed to
    // the prepare() function of a HotDrink object.
    std::cout << "Grind some beans, boil water, pour " << volume << "ml, add sugar, enjoy!\n";
}