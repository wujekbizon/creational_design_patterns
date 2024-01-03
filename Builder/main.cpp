#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

struct HtmlBuilder;

// Defining the HtmlElement class
class HtmlElement
{
    // Defining the HtmlBuilder class as a friend class
    friend class HtmlBuilder;

    // Member variables of the HtmlElement class
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;

    /**
     * Default constructor for the `HtmlElement` class
     */
    HtmlElement() = default;

    /**
     * Constructor for the `HtmlElement` class with name and text
     * @param name The name of the HTML element tag
     * @param text Text content for the element
     */
    HtmlElement(const std::string &name, const std::string &text) : name(name), text(text)
    {
    }

  public:
    // destructor
    ~HtmlElement()
    {
    }
    /**
     * Getter for the element's name
     * @return The name of the HTML element tag
     */
    std::string getName() const
    {
        return name;
    }

    /**
     * Getter for the element's text content
     * @return Text content for the element
     */
    std::string getText() const
    {
        return text;
    }

    /**
     * Getter for the vector of child HTML elements
     * @return Vector of child HTML elements
     * This is a non-const getter that returns a modifiable reference to the elements vector. This allows for modifying
     * the vector of child elements directly. For instance, a HtmlBuilder instance could use this getter to add child
     * elements to an existing HtmlElement object.
     */
    std::vector<HtmlElement> &getElements()
    {
        return elements;
    }

    /**
     * Getter for the const vector of child HTML elements
     * @return Const vector of child HTML elements
     * This is a const getter that returns a const reference to the elements vector. This prevents the vector from being
     * modified directly. It's typically used when only reading the contents of the vector is required, such as when
     * iterating over the child elements.
     */
    const std::vector<HtmlElement> &getElements() const
    {
        return elements;
    }

    /**
     * Static method to create a new `HtmlBuilder` instance
     * @param rootName The name of the root element
     * @return Unique pointer to the new `HtmlBuilder` instance
     */
    static std::unique_ptr<HtmlBuilder> build(std::string rootName)
    {
        return make_unique<HtmlBuilder>(rootName);
    }
};

class HtmlRenderer
{
  public:
    // Indent size for nested elements
    const size_t indent_size = 2;
    // Method to generate the HTML string representation of the element
    std::string str(const HtmlElement &element, int indent = 0) const
    {
        // Create an ostringstream to build the HTML string
        std::ostringstream oss;

        // Generate indentation based on the current level
        std::string i(indent_size * indent, ' ');

        // Get the name, text and elements from the HtmlElement object
        auto name = element.getName();
        auto text = element.getText();
        auto elements = element.getElements();

        // Add the opening tag of the element
        oss << i << "<" << name << ">" << std::endl;

        // Add the element's text content if not empty
        if (text.size() > 0)
            oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;

        // Recursively generate HTML strings for child elements
        for (const auto &e : elements)
            oss << str(e, indent + 1);

        // Add the closing tag of the element
        oss << i << "</" << name << ">" << std::endl;
        // Return the complete HTML string
        return oss.str();
    }
};

// Implementation of the HtmlBuilder struct
class HtmlBuilder
{
  public:
    // Constructor for the HtmlBuilder class with root element name
    HtmlBuilder(std::string rootName)
    {
        root.name = rootName;
    }

    // Method to add a child element with reference semantics
    HtmlBuilder &addChildByRef(std::string childName, std::string childText)
    {
        HtmlElement e{childName, childText};
        root.elements.emplace_back(e);
        return *this;
    }

    // Method to add a child element with pointer semantics
    HtmlBuilder *addChildByPoint(std::string childName, std::string childText)
    {
        HtmlElement e{childName, childText};
        root.elements.emplace_back(e);
        return this;
    }

    // Method to get the HTML string representation of the root element
    std::string str()
    {
        return renderer.str(root);
    }

    // Method to return the root element as an HtmlElement object
    operator HtmlElement() const
    {
        return root;
    }

    // Member variable of the HtmlBuilder class
    HtmlElement root;
    HtmlRenderer renderer;
};

int main()
{
    // Example of generating HTML with text content
    auto text = "hello";
    std::string output;
    output += "<p>";
    output += text;
    output += "</p>";
    printf("<p>%s</p>", text);

    // Example of generating HTML with a list of items
    std::string words[] = {"hello", "world"};
    std::ostringstream oss;
    oss << "<ul>";
    for (auto w : words)
        oss << "  <li>" << w << "</li>";
    oss << "</ul>";
    printf(oss.str().c_str());

    // Example of using the HtmlBuilder class
    HtmlBuilder builder{"ul"};
    builder.addChildByRef("li", "hello").addChildByRef("li", "world");
    std::cout << builder.str() << std::endl;

    // Example of using the HtmlBuilder::build() method
    auto builder2 = HtmlElement::build("ul");
    builder2->addChildByPoint("li", "hello")->addChildByPoint("li", "world");
    std::cout << builder2->str() << std::endl;

    // is inaccessible
    // HtmlElement e;

    getchar();
    return 0;
}