#include <iostream>
using namespace std;

class OneWife
{
    public:
    // Some methods
    static OneWife* getInstance()
    {
        if(!instance)
        {
            instance = new OneWife();
        }
        return instance;
    }
    void someOperation()
    {
        cout << "Some operation() \n";
    }
    
    // Deleted copy constructor and assignment operator
    OneWife(const OneWife&) = delete;
    OneWife& operator = (const OneWife&) = delete;
    private:
    OneWife() 
    {
        cout << "Private Constructor called!! \n";
        cout << "Counter= "<<counter++ << endl;
    }
    ~OneWife() {cout << "Destructor called!!\n";}
    static OneWife* instance; // a static instance variable
    static int counter;
};

OneWife* OneWife::instance = nullptr;
int OneWife::counter = 0;

int main() {
    
    OneWife* oneWife = OneWife::getInstance();
    oneWife->someOperation();
    
    
    oneWife = OneWife::getInstance();
    oneWife->someOperation();
    
    OneWife* oneWife1 = OneWife::getInstance();
    oneWife1->someOperation();

    
    //delete oneWife;
    //delete oneWife1;
    

    return 0;
}