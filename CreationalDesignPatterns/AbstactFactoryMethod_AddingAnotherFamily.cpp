// Abstact Factory Method
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

class LahoreMargeritaPizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout
            << "Baking Lahore-style margrita pizza."
            << std::endl;
    }
 
    void cut() override
    {
        std::cout
            << "Cutting Lahore-style margrita pizza."
            << std::endl;
    }
 
    void box() override
    {
        std::cout
            << "Boxing Lahore-style margrita pizza."
            << std::endl;
    }
};

class FaisalabadCheesePizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout << "Baking Faisalabad-style cheese pizza."
                  << std::endl;
    }
 
    void cut() override
    {
        std::cout << "Cutting Faisalabad-style cheese pizza."
                  << std::endl;
    }
 
    void box() override
    {
        std::cout << "Boxing Faisalabad-style cheese pizza."
                  << std::endl;
    }
    
};

class FaisalabadPeproniPizza : public Pizza
{
    public:
    void bake() override
    {
        std::cout
            << "Baking Faisalabad-style pepperoni pizza."
            << std::endl;
    }
 
    void cut() override
    {
        std::cout
            << "Cutting Faisalabad-style pepperoni pizza."
            << std::endl;
    }
 
    void box() override
    {
        std::cout
            << "Boxing Faisalabad-style pepperoni pizza."
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
    //virtual Pizza* createMargritaPizza() = 0;
    virtual Pizza* createMargritaPizza()
    {
        std::cout << "Base Function\n";
        return nullptr;
    }
};

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
    
    Pizza* createMargritaPizza() override
    {
        return new LahoreMargeritaPizza();
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
    
    /*
    Pizza* createMargritaPizza() override 
    {
        throw std::logic_error("Not implemented in KarachiPizzaFactory");
    }
    */
    
};

class FaisalabadPizzaFactory : public PizzaFactory
{
    public:
    Pizza* createCheesePizza() override
    {
        return new FaisalabadCheesePizza();
    }
    
    Pizza* createPeproniPizza() override
    {
        return new FaisalabadPeproniPizza();
    }
};




int main() {
    PizzaFactory* lahorePizzaFactory = 
    new LahorePizzaFactory();
    Pizza* lahoriCheesePizza = lahorePizzaFactory->createCheesePizza();
    Pizza* lahoriPeproniPizza = lahorePizzaFactory->createPeproniPizza();
    Pizza* lahoriMargritaPizza = lahorePizzaFactory->createMargritaPizza();
    
    lahoriCheesePizza->bake();
    lahoriCheesePizza->cut();
    lahoriCheesePizza->box();
    
    std::cout << "\n";
    
    lahoriMargritaPizza->bake();
    lahoriMargritaPizza->cut();
    lahoriMargritaPizza->box();
    
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
    
    std::cout << "Faisalabadi is here to rock!! \n";
    
    PizzaFactory* fsdPizzaFactory =
    new FaisalabadPizzaFactory();
    Pizza* fsdCheesePizza = fsdPizzaFactory->createCheesePizza();
    Pizza* fsdPeproniPizza = fsdPizzaFactory->createPeproniPizza();
    
    fsdCheesePizza->bake();
    fsdCheesePizza->cut();
    fsdCheesePizza->box();
    
    std::cout << "\n";
    
    fsdPeproniPizza->bake();
    fsdPeproniPizza->cut();
    fsdPeproniPizza->box();
    

    return 0;
}