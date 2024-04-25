// It provides an interface for creating families of related or dependent objects without specifying their concrete classes. This pattern is a way to 
// encapsulate the creation of objects and ensure that they are compatible and properly configured.

// Best Comment: It helps to create families of objects.
#include <iostream>

class Pizza
{
    // virtual poly morphic methods
    public:
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

class LahoreCheesePizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout << "Baking Lahore-style cheese pizza."
                  << std::endl;
    }
 
    void cut() override
    {
        std::cout << "Cutting Lahore-style cheese pizza."
                  << std::endl;
    }
 
    void box() override
    {
        std::cout << "Boxing Lahore-style cheese pizza."
                  << std::endl;
    }
    
};

class LahorePeproniPizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout
            << "Baking Lahore-style pepperoni pizza."
            << std::endl;
    }
 
    void cut() override
    {
        std::cout
            << "Cutting Lahore-style pepperoni pizza."
            << std::endl;
    }
 
    void box() override
    {
        std::cout
            << "Boxing Lahore-style pepperoni pizza."
            << std::endl;
    }
    
};

class KarachiCheesePizza : public Pizza
{
        public:
    void bake() override
    {
        std::cout << "Baking Karachi-style cheese pizza."
                  << std::endl;
    }
 
    void cut() override
    {
        std::cout << "Cutting Karachi-style cheese pizza."
                  << std::endl;
    }
 
    void box() override
    {
        std::cout << "Boxing Karachi-style cheese pizza."
                  << std::endl;
    }
    
};

class KarachiPeproniPizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout << "Baking Karachi-style peproni pizza."
                  << std::endl;
    }
 
    void cut() override
    {
        std::cout << "Cutting Karachi-style peproni pizza."
                  << std::endl;
    }
 
    void box() override
    {
        std::cout << "Boxing Karachi-style peproni pizza."
                  << std::endl;
    }
    
};

class PizzaFactory
{
    public:
    virtual Pizza* createCheesePizza() = 0;
    virtual Pizza* createPeproniPizza() = 0;
    
};

// Two factories
class LahorePizzaFactory : public PizzaFactory
{
    public:
    Pizza* createCheesePizza() override
    {
        return new LahoreCheesePizza();
    }
    
    Pizza* createPeproniPizza() override
    {
        return new LahorePeproniPizza();
    }
};

class KarachiPizzaFactory : public PizzaFactory
{
    public:
    Pizza* createCheesePizza() override
    {
        return new KarachiCheesePizza();
    }
    
    Pizza* createPeproniPizza() override
    {
        return new KarachiPeproniPizza();
    }
    
};




int main() {
    PizzaFactory* lahorePizzaFactory = 
    new LahorePizzaFactory();
    Pizza* lahoriCheesePizza = lahorePizzaFactory->createCheesePizza();
    Pizza* lahoriPeproniPizza = lahorePizzaFactory->createPeproniPizza();
    
    lahoriCheesePizza->bake();
    lahoriCheesePizza->cut();
    lahoriCheesePizza->box();
    
    std::cout << "\n";
    
    lahoriPeproniPizza->bake();
    lahoriPeproniPizza->cut();
    lahoriPeproniPizza->box();
    
    std::cout << "\n";
    
    PizzaFactory* karachiPizzaFactory =
    new KarachiPizzaFactory();
    Pizza* karachiCheesePizza = karachiPizzaFactory->createCheesePizza();
    Pizza* karachiPeproniPizza = karachiPizzaFactory->createPeproniPizza();
    
    karachiCheesePizza->bake();
    karachiCheesePizza->cut();
    karachiCheesePizza->box();
    
    std::cout << "\n";
    
    karachiPeproniPizza->bake();
    karachiPeproniPizza->cut();
    karachiPeproniPizza->box();
    

    return 0;
}