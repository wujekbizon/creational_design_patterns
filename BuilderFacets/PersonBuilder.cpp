#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonAddressBuilder PersonBuilderBase::lives() const
{
    // Returns a `PersonAddressBuilder` object for setting the person's address.
    // Creates a new `PersonAddressBuilder` object and passes the `person` reference to it.
    return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilderBase::works() const
{
    // Returns a `PersonJobBuilder` object for setting the person's employment details.
    // Creates a new `PersonJobBuilder` object and passes the `person` reference to it.
    return PersonJobBuilder{person};
}