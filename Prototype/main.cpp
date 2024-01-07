#include <iostream>
#include <sstream>

/*
Simple implementation of the prototype design pattern.
*/

class Address
{
  public:
    // Member variables representing the street address, city, and suite number.
    std::string street;
    std::string city;
    int suite;

    // Constructor for creating an 'Address' object with the specified street, city, and suite number.
    Address(const std::string &street, const std::string &city, int suite) : street(street), city(city), suite(suite)
    {
    }

    // Copy constructor for creating a copy of the 'Address' object.
    Address(const Address &address) : street{address.street}, city{address.city}, suite{address.suite}
    {
    }

    // Overloaded output operator for printing the address information.
    friend std::ostream &operator<<(std::ostream &os, const Address &address)
    {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

class Contact
{
    // Member variables for storing the person's name and address pointer.
  public:
    std::string name;
    Address *address;

    // Constructor for creating a 'Contact' object with the specified name and address pointer.
    Contact(const std::string &name, Address *address) : name(name), address(address)
    {
    }

    // Copy constructor for creating a copy of the 'Contact' object.
    Contact(const Contact &other) : name{other.name}, address{new Address{*other.address}}
    {
    }

    // Overloaded output operator for printing the contact information.
    friend std::ostream &operator<<(std::ostream &os, const Contact &contact)
    {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }
};

int main()
{
    // Original contact `john` is acting as a prototype
    Contact john{"John Doe", new Address{"123 East Dr", "London", 123}};
    // Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    // Contact jane = john; // shallow copy
    // jane.name = "Jane Smith";
    // jane.address->suite = 103;

    // replicate the prototype by using a copy constructor
    Contact jane{john};
    // then we customize the resulting instance. We set the different name as well as a part of the address
    jane.name = "Jane Smith";
    jane.address->suite = 103;

    std::cout << john << std::endl;
    std::cout << jane << std::endl;

    return 0;
}