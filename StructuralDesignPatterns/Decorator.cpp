#include <iostream>
using namespace std;

// Component Interface
class IceCream
{
    public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
};

// Concrete Component serve as Base
class VannilaIceCream : public IceCream
{
    public:
    string getDescription() const override
    {
        return "Vanilla Ice Cream";
    }
    double getCost() const override
    {
        return 160.0;
    }
};


// Decorator Interface 
class IceCreamDecorator : public IceCream
{
    protected:
    IceCream* iceCream;
    IceCreamDecorator(IceCream* ic) : iceCream(ic) {}
    public:
    string getDescription() const override
    {
        return iceCream->getDescription();
    }
    
    double getCost() const override
    {
        return iceCream->getCost();
    }
};

// Concrete Decorator/+s
// choco decorator
class ChocoDecorator : public IceCreamDecorator
{
    public:
    ChocoDecorator(IceCream* ic)
        : IceCreamDecorator(ic)
    {
    }
    string getDescription() const override
    {
        return iceCream->getDescription() + " with chocolate";
    }
    
    double getCost() const override
    {
        return iceCream->getCost() + 10.0;
    }
    
};

class SparkleDecorator : public IceCreamDecorator
{
    public:
    SparkleDecorator(IceCream* ic)
        : IceCreamDecorator(ic)
    {
    }
    string getDescription() const override
    {
        return iceCream->getDescription() + " with sparkle";
    }
    
    double getCost() const override
    {
        return iceCream->getCost() + 5.0;
    }
    
};



int main() {
    IceCream* vanilaIceCream = new VannilaIceCream();
    cout << "Your Order: " << vanilaIceCream->getDescription()
    << ", Cost: Rs." <<vanilaIceCream->getCost() << endl;
    
     IceCream* chocolateIceCream = new ChocoDecorator(vanilaIceCream);
    cout << "Your Final Order: " << chocolateIceCream->getDescription()
    << ", Cost: Rs." <<chocolateIceCream->getCost()<< endl;
    
    IceCream* sparkleIceCream = new SparkleDecorator(chocolateIceCream);
    cout << "Your Final Order: " << sparkleIceCream->getDescription()
    << ", Cost: Rs." <<sparkleIceCream->getCost();
     
     

    return 0;
}