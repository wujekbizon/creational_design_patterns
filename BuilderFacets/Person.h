#pragma once
#include <iostream>
#include <string>

class PersonBuilder;

class Person
{
    // Address
    std::string streetAddress; // Represents the street address of the person
    std::string postCode;      // Represents the postal code of the person's address
    std::string city;          // Represents the city where the person lives

    // Employment
    std::string companyName; // Represents the name of the person's company
    std::string position;    // Represents the person's job title or position
    int annualIncome = 0;    // Represents the person's annual income

    Person()
    {
        // Prints a message indicating the creation of a new Person object
        std::cout << "Person created\n";
    }

  public:
    ~Person()
    {
        // Prints a message indicating the destruction of a Person object
        std::cout << "Person destroyed\n";
    }

    // A static method that returns a new `PersonBuilder` object
    static PersonBuilder create();

    // Move constructor
    // we using to efficiently transfer ownership of data from one Person object to another.
    Person(Person &&other) // Creates a new `Person` object by moving the data from the `other` object. This avoids
                           // copying large objects and improves performance.
        : streetAddress(std::move(
              other.streetAddress)), // Moves the `streetAddress` from the `other` object to the current object.
          postCode(std::move(other.postCode)), // Moves the `postCode` from the `other` object to the current object.
          city(std::move(other.city)),         // Moves the `city` from the `other` object to the current object.
          companyName(
              std::move(other.companyName)),   // Moves the `companyName` from the `other` object to the current object.
          position(std::move(other.position)), // Moves the `position` from the `other` object to the current object.
          annualIncome(other.annualIncome) // Moves the `annualIncome` from the `other` object to the current object.
    {
    }

    // Move assignment operator
    Person &operator=(Person &&other)
    { // Replaces the current `Person` object with the data from the `other` object using move semantics.
        if (this == &other)
        { // Handles self-assignment, as it would be inefficient to move data from the same object to itself.
            return *this;
        }

        // Moves the data from the `other` object to the current object.
        streetAddress = std::move(other.streetAddress);
        postCode = std::move(other.postCode);
        city = std::move(other.city);
        companyName = std::move(other.companyName);
        position = std::move(other.position);
        annualIncome = other.annualIncome;

        return *this; // Returns a reference to the current object, now updated with the data from the `other` object.
    }

    // Overloaded output operator to print the person's details in a formatted manner.
    friend std::ostream &operator<<(std::ostream &os, const Person &obj)
    {
        return os << "street_address: " << obj.streetAddress << " post_code: " << obj.postCode << " city: " << obj.city
                  << " company_name: " << obj.companyName << " position: " << obj.position
                  << " annual_income: " << obj.annualIncome;
    }

    friend class PersonBuilder;
    // Friend declaration for `PersonBuilder` class. This allows `PersonBuilder` to access private members of the
    // `Person` class.
    friend class PersonJobBuilder; // Friend declaration for `PersonJobBuilder` class. This allows `PersonJobBuilder` to
                                   // access private members of the `Person` class.
    friend class PersonAddressBuilder; // Friend declaration for `PersonAddress
};

/*
Move semantics is a feature of C++ that allows you to efficiently transfer ownership of resources from one object to
another. In the Person class, the move constructor and move assignment operator utilize move semantics to improve
performance, especially when dealing with large objects. By moving data rather than copying it, move semantics can
significantly reduce memory usage and improve performance, especially when constructing large objects or transferring
ownership of resources. This makes it a valuable tool for efficient and optimized code.
*/