#pragma once
#include <iostream>
#include <memory>
#include <string>

class HotDrink
{
  public:
    // This is a pure virtual function. It means that all
    // subclasses of HotDrink must implement this function.
    // The = 0 means that the function must return a value
    // of type void, and it does not have a default implementation.
    virtual ~HotDrink() = default;
    virtual void prepare(const int &volume) = 0;
};

class Tea : public HotDrink
{
  public:
    // This overrides the prepare() function defined in the
    // HotDrink class. The override keyword is used to tell the
    // compiler that we are intentionally overriding a function
    // in the base class.
    void prepare(const int &volume) override;
};

class Coffee : public HotDrink
{
  public:
    // This overrides the prepare() function defined in the
    // HotDrink class.
    void prepare(const int &volume) override;
};