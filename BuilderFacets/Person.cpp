#include "Person.h"
#include "PersonBuilder.h"

// Creates a new `PersonBuilder` object to facilitate the construction of a `Person` object with various attributes.
PersonBuilder Person::create()
{
    return PersonBuilder(); // Returns a new `PersonBuilder` object with no predefined values.
}