
#include <iostream>
#include <memory>
using namespace std;

class MyApp
{
    public:
    virtual ~MyApp() {}
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
    virtual unique_ptr<MyApp> createOrder(string type) = 0; // serve as FM
};

// Now we will create Two factories/families: Willy's and ICA factory

class WillyFactory : public AppFactory
{
    public:
    unique_ptr<MyApp> createOrder(string type) override
    {
        if(type == "snacks")
        {
            return make_unique<WillySnacks>();
        }
        else if (type == "dairy")
        {
            return make_unique<WillyDairy>();
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
    unique_ptr<MyApp> createOrder(string type) override
    {
        if(type == "snacks")
        {
            return make_unique<IcaSnacks>();
        }
        else if (type == "dairy")
        {
            return make_unique<IcaDairy>();
        }
        else
        {
            return nullptr;
        }
    }
};

int main() {
    
    
    int numOrders;
    std::cout << "Enter the number of orders: ";
    std::cin >> numOrders;

    for (int i = 0; i < numOrders; ++i) 
    {
        std::string orderType;
        std::cout << "Enter order type (snacks/dairy): ";
        std::cin >> orderType;

        std::string storeChoice;
        std::cout << "Select store (ICA/Willy's): ";
        std::cin >> storeChoice;

        std::unique_ptr<AppFactory> factory;
        if (storeChoice == "ICA") {
            factory = std::make_unique<IcaFactory>();
        } else if (storeChoice == "Willy's") 
        {
            factory = std::make_unique<WillyFactory>();
        } 
        else 
        {
            std::cout << "Invalid store choice. Please enter 'ICA' or 'Willy's'." << std::endl;
            continue;
        }
        
        try {
            std::unique_ptr<MyApp> order = factory->createOrder(orderType);
            order->order();
        } 
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    return 0;
}