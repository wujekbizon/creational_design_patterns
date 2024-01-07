#include <iostream>
#include <sstream>

class Address
{
  public:
    Address(const std::string &street, const std::string &city, int suite) : street(street), city(city), suite(suite)
    {
    }
    std::string street;
    std::string city;
    int suite;

    friend std::ostream &operator<<(std::ostream &os, const Address &address)
    {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

class Contact
{

  public:
    std::string name;
    Address *address;
    Contact(const std::string &name, Address *address) : name(name), address(address)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const Contact &contact)
    {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }
};

int main()
{
    Contact john{"John Doe", new Address{"123 East Dr", "London", 123}};
    // Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    Contact jane = john;
    jane.name = "Jane Smith";
    jane.address->suite = 103;

    std::cout << john << std::endl << jane << std::endl;

    return 0;
}