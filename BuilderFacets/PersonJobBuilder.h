#pragma once
#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase
{
    // Defines an alias for the `PersonJobBuilder` type for conciseness and readability
    typedef PersonJobBuilder Self;

  public:
    // Constructor initializes the `person` reference
    explicit PersonJobBuilder(Person &person) : PersonBuilderBase{person}
    {
    }

    // Sets the person's company name
    Self &at(const std::string &companyName)
    {
        person.companyName = companyName; // Sets the person's company name to the given value
        return *this;                     // Returns the current builder object for chaining further method calls
    }

    // Sets the person's job title or position
    Self &asA(const std::string &position)
    {
        person.position = position; // Sets the person's job title or position to the given value
        return *this;               // Returns the current builder object for chaining further method calls
    }

    // Sets the person's annual income
    Self &earning(const int &annualIncome)
    {
        person.annualIncome = annualIncome; // Sets the person's annual income to the given value
        return *this;                       // Returns the current builder object for chaining further method calls
    }
};