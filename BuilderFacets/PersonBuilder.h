#pragma once
#include "Person.h"

class PersonAddressBuilder; // Forward declaration of `PersonAddressBuilder` class
class PersonJobBuilder;     // Forward declaration of `PersonJobBuilder` class

// A base class for constructing `Person` objects
class PersonBuilderBase
{
    // Access specifier for member variables is `protected`, allowing only derived classes to access them
  protected:
    // Reference to the `Person` object being constructed
    Person &person;

    // Explicit constructor initializes the `person` reference
    explicit PersonBuilderBase(Person &person) : person(person)
    {
    }

  public:
    // Converts the `PersonBuilderBase` object to a `Person` object
    operator Person() const
    {
        // Transfers ownership of the `person` object to the returned `Person` object
        return std::move(person);
    }

    /*
    This method returns a PersonAddressBuilder object that allows setting the address of the
     person being constructed. It creates a new PersonAddressBuilder object and passes the person
     reference to it. This method serves as a transition point between setting the person's overall
     properties and focusing on their address specifically.
    */
    PersonAddressBuilder lives() const;

    /*
    This method returns a PersonJobBuilder object that allows setting the employment details of the
    person being constructed. It creates a new PersonJobBuilder object and passes the person reference
    to it. This method serves as a transition point between setting the person's overall properties
    and focusing on their employment details specifically.
    */
    PersonJobBuilder works() const;
};

// Derived class from `PersonBuilderBase`
class PersonBuilder : public PersonBuilderBase
{
    // Member variable of type `Person`
    Person p;

  public:
    // Constructor initializes the `p` member variable using the base class constructor
    PersonBuilder() : PersonBuilderBase{p}
    {
    }
};