#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

class Tag
{
  public:
    std::string name;          // Define the name of the tag
    std::string text;          // Define the text content within the tag
    std::vector<Tag> children; // Define a vector of child tags
    // Define a vector of attribute pairs (name, value)
    std::vector<std::pair<std::string, std::string>> attributes;

    // defined the stream output operator on the tag to print all the tags
    // including all the children and all the content correctly.
    // The friend keyword is used to allow access to private members of a
    // class from outside the class hierarchy.
    friend std::ostream &operator<<(std::ostream &os, const Tag &tag)
    {
        // Open the tag with its name and attributes
        os << "<" << tag.name;

        // Iterate through the attributes and print them
        for (const auto &att : tag.attributes)
            os << " " << att.first << "=\"" << att.second << "\"";

        // Check if the tag has children or text content
        if (tag.children.size() == 0 && tag.text.length() == 0)
        { // If the tag has neither children nor text, print the closing tag
            os << "/>" << std::endl;
        }
        else
        {
            // If the tag has either children or text, print the opening tag and newline
            os << ">" << std::endl;

            // Conditional check for the presence of text content
            if (tag.text.length())
                // If there is text content, print the text and newline
                os << tag.text << std::endl;

            // Iterate through the children and print their contents
            for (const auto &child : tag.children)
                os << child;

            // Close the tag
            os << "</" << tag.name << ">" << std::endl;
        }

        // Return the output stream object
        return os;
    }

    // The protected access modifier is used to make these constructors accessible only to subclasses of the Tag class.
  protected:
    // Protected constructor for tags with text content
    Tag(const std::string &name, const std::string &text) : name(name), text(text)
    {
    }
    // Protected constructor for tags with child tags
    Tag(const std::string &name, const std::vector<Tag> &children) : name(name), children(children)
    {
    }
};

class P : public Tag
{
  public:
    // Constructor for paragraph tags
    P(const std::string &text) : Tag("p", text)
    {
    }

    // Constructor for paragraph tags with children
    P(std::initializer_list<Tag> children) : Tag{"p", children}
    {
    }
};

class IMG : public Tag
{
  public:
    // Constructor for image tags with a URL attribute
    explicit IMG(const std::string &url) : Tag{"img", ""}
    {
        // Add the `src` attribute with the provided URL
        attributes.emplace_back(std::make_pair("src", url));
    }
};

int main()
{
    // Construct a paragraph tag with an embedded image tag
    std::cout <<

        P{IMG{"http://pokemon.com/pikachu.png"}}

              << std::endl;

    return 0;
}

/*
Delving into the Builder Pattern: Creating HTML Elements in C++
The Builder pattern is a creational design pattern that separates the construction of a
complex object from its representation. This pattern allows for a more flexible and
controlled way of creating objects, especially those with complex configurations.
In this blog post, we'll explore the Builder pattern using an example of constructing
HTML elements in C++.

Understanding the Code Snippet
The provided code snippet defines a class hierarchy for representing HTML elements.
The base class Tag represents the generic structure of an HTML tag, including its name,
attributes, text content, and child tags. This class also defines a friend function
operator << that efficiently prints the structured representation of an HTML document.
The derived classes P (for paragraph) and IMG (for image) inherit from the Tag class
and specialize its behavior for their respective elements. P handles paragraph content,
while IMG manages image attributes and the URL of the embedded image.

Encapsulating Tag Creation with Protected Constructors
The Tag class employs protected constructors to encapsulate the creation of tag objects.
These constructors are only accessible to subclasses, ensuring that only specific types
of tags can be created. This approach helps to enforce data integrity and prevent invalid
tag instances from being created.

Using Uniform Initialization for Tag Configuration
The code utilizes uniform initialization to simplify the configuration of tag objects.
This approach involves using curly braces ({}) to explicitly pass the tag name, text content,
or child tags. This makes the code more readable and reduces the likelihood of errors.

Introducing the explicit Keyword for Type Safety
The IMG class uses the explicit keyword for its constructor. This keyword prevents implicit
conversions, ensuring that only valid URL strings can be used to create image tags.
This enhances type safety and prevents unintended or ambiguous conversions.

Building HTML Structures with Inheritance and Friend Function
The combination of inheritance and the operator<< friend function allows for the construction
of hierarchical HTML structures. The Tag class hierarchy provides the base for different HTML
elements, while the operator<< function efficiently prints the rendered output.

Conclusion
The provided example demonstrates the application of the Builder pattern to construct HTML
elements in C++. By using protected constructors, uniform initialization, and the explicit keyword,
the code ensures type safety, flexibility, and maintainability. This approach can be applied to
various scenarios where complex objects require a structured and controlled construction process.
*/