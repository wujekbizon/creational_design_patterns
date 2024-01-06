#pragma once
#include "PersonBuilder.h"

class PersonAddressBuilder : public PersonBuilderBase
{
    // Defines an alias for the `PersonAddressBuilder` type for conciseness and readability
    typedef PersonAddressBuilder Self;

  public:
    // Constructor initializes the `person` reference
    explicit PersonAddressBuilder(Person &person) : PersonBuilderBase{person}
    {
    }

    // Sets the person's street address
    Self &at(const std::string &streetAddress)
    {
        person.streetAddress = streetAddress; // Sets the person's street address to the given value
        return *this;                         // Returns the current builder object for chaining further method calls
    }

    // Sets the person's postal code
    Self &withPostCode(const std::string &postCode)
    {
        person.postCode = postCode; // Sets the person's postal code to the given value
        return *this;               // Returns the current builder object for chaining further method calls
    }

    // Sets the person's city
    Self &in(const std::string &city)
    {
        person.city = city; // Sets the person's city to the given value
        return *this;       // Returns the current builder object for chaining further method calls
    }
};