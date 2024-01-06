#include "Person.h"
#include "PersonAddressBuilder.h"
#include "PersonBuilder.h"
#include "PersonJobBuilder.h"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

int main()
{
    // Creates a new `Person` object using the `Person::create()` method
    Person p = Person::create()
                   .lives()                 // Starts setting the person's address using the `lives()` method
                   .at("123 London Road")   // Sets the street address using the `at()` method
                   .withPostCode("SW1 1GB") // Sets the postal code using the `withPostCode()` method
                   .in("London")            // Sets the city using the `in()` method
                   .works()                 // Starts setting the person's employment details using the `works()` method
                   .at("WesaSoft")          // Sets the company name using the `at()` method
                   .asA("Developer")        // Sets the job title or position using the `asA()` method
                   .earning(10e6);          // Sets the annual income using the `earning()` method

    // Prints the `Person` object to the console using the `std::cout` stream
    std::cout << p << std::endl;

    return 0;
}