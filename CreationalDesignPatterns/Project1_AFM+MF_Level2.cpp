// createOrder() serve as FM (provide surface but derived classes implement those surfaces), whereas  WillyFactory and IcaFactory serves as two families (AFM).
#include <iostream>
using namespace std;

class MyApp
{
    public:
    //virtual ~MyApp() {}
    virtual void order() = 0;
};

class WillySnacks : public MyApp
{
    public:
    void order() override
    {
        cout << "CONFIRMATION: Snacks order received by Willy's \n";
    }
};

class WillyDairy : public MyApp
{
    void order() override
    {
        cout << "CONFIRMATION: Dairy order received by Willy's \n";
    }
};

class IcaSnacks : public MyApp
{
    void order() override
    {
        cout << "CONFIRMATION: Snacks order received by ICA \n";
    }
};

class IcaDairy : public MyApp
{
    void order() override
    {
        cout << "CONFIRMATION: Dairy order received by ICA \n";
    }
};

class AppFactory
{
    public:
    virtual MyApp* createOrder(string type) = 0; // serve as FM
};

// Now we will create Two factories/families: Willy's and ICA factory

class WillyFactory : public AppFactory
{
    public:
    MyApp* createOrder(string type) override
    {
        if(type == "snacks")
        {
            return new WillySnacks();
        }
        else if (type == "dairy")
        {
            return new WillyDairy();
        }
        else
        {
            return nullptr;
        }
        
    }
};

class IcaFactory : public AppFactory
{
    public:
    MyApp* createOrder(string type) override
    {
        if(type == "snacks")
        {
            return new IcaSnacks();
        }
        else if (type == "dairy")
        {
            return new IcaDairy();
        }
        else
        {
            return nullptr;
        }
    }
};

int main() {
    
    // Snacks order at Willy's
    AppFactory* factory;
    MyApp* order;
    
    factory = new WillyFactory();
    order = factory->createOrder("snacks");
    order->order();
    
    delete factory;
    delete order;
    
    // Dairy order at ICA
    
    //AppFactory* factory;
    //MyApp* order;
    
    factory = new IcaFactory();
    order = factory->createOrder("dairy");
    order->order();
    
    
    
    
    
    
    
    

    return 0;
}