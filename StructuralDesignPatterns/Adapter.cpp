#include <iostream>
using namespace std;

// interface
class runMac
{
    public:
    virtual void run() = 0;
};

class LegacyMac
{
    public:
    void macRunner()
    {
        cout << "Mac OS is Up and running \n";
    };
};

class LegacyWindow98
{
    public:
    void winRunner()
    {
        cout << "Window 98 is Up and running \n";
    };
};

class Adapter : public runMac
{
    public:
    LegacyMac legacyMac;
    LegacyWindow98 legacyWindow98;
    void run() override
    {
        legacyMac.macRunner();
        legacyWindow98.winRunner();
    }
};

void client(Adapter& adapter)
{
    adapter.run();
}

int main() {
    
    Adapter adapter;
    client(adapter);

    return 0;
}