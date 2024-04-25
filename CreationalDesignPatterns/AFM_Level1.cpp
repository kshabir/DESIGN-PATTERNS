
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
    virtual MyApp* createSnacksOrder() = 0;
    virtual MyApp* createDairyOrder() = 0;
    
};

// Now we will create Two factories/families: Willy's and ICA factory

class WillyFactory : public AppFactory
{
    public:
    MyApp* createSnacksOrder() override
    {
        return new WillySnacks();
    }
    MyApp* createDairyOrder() override
    {
        return new WillyDairy();
    }
};

class IcaFactory : public AppFactory
{
    public:
    MyApp* createSnacksOrder() override
    {
        return new IcaSnacks();
    }
    MyApp* createDairyOrder() override
    {
        return new IcaDairy();
    }
};

int main() {
    AppFactory* wilFactory = new WillyFactory();
    AppFactory* icaFactory = new IcaFactory();
    
    MyApp* willSnacks = wilFactory->createSnacksOrder();
    willSnacks->order();
    
    auto icaDairy = icaFactory->createDairyOrder();
    icaDairy->order();
    

    return 0;
}