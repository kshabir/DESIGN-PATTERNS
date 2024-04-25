#include <iostream>
using namespace std;

// Builder (Keywords: CONSTRUCTION & REPRESENTATION): It helps to separate construction of an object from it's representation.
// USAGE: Usefull to add different configurations in an object e.g a book consist of header, chapters, contents etc.


// Product (components: cpu, memory, storage)
class Computer
{
    public:
    void setCPU(const string& cpu)
    {
        m_cpu = cpu;
    }
    void setMemory(const string& mem)
    {
        m_memory = mem;
    }
    void setStorage(const string& storage)
    {
        m_storage = storage;
    }
    
    void display()
    {
        std::cout << "CPU: " << m_cpu << std::endl;
        std::cout << "Memory: " << m_memory << std::endl;
        std::cout << "Storage: " << m_storage << std::endl;
    }
    
    private:
    string m_cpu;
    string m_memory;
    string m_storage;
    
};

// builder interface, concrete builder

class Builder
{
    public:
    virtual void buildCPU(const string& cpu) = 0;
    virtual void buildMemory(const string& mem) = 0;
    virtual void buildStorage(const string& sto) = 0;
    virtual Computer getProduct() = 0;

};

class DesktopComputerBuilder : public Builder
{
    public:
    DesktopComputerBuilder()
    {
        computer = Computer();
    }
    void buildCPU(const string& cpu) override
    {
        computer.setCPU(cpu);
    }
    void buildMemory(const string& mem) override
    {
        computer.setMemory(mem);
    }
    void buildStorage(const string& sto) override
    {
        computer.setStorage(sto);
    }
    Computer getProduct() override
    {
        return computer;
    }
    
    private:
    Computer computer;
    
};

// Director
class ComputerAssembler
{
    public:
    Computer assembelComputer(Builder& builder)
    {
        builder.buildCPU("i7");
        builder.buildMemory("16GB");
        builder.buildStorage("520GB SSD");
        
        return builder.getProduct();
    }
};


int main() {
    ComputerAssembler computerAssembler;
    DesktopComputerBuilder builder;
    Computer computer = computerAssembler.assembelComputer(builder);
    
    std::cout << "My Desktop configuration: \n";
    computer.display();
    
    

    return 0;
}