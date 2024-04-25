/*Two separate computer types (Desktop and Macbook) having some common and different configurations*/

#include <iostream>
#include <string>
using namespace std;

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
    void setVersion(const string& ver)
    {
        m_version = ver;
    }
    
    void display()
    {
        std::cout << "CPU: " << m_cpu << std::endl;
        std::cout << "Memory: " << m_memory << std::endl;
        std::cout << "Storage: " << m_storage << std::endl;
        if(!m_version.empty())
        {
            std::cout << "Version: " << m_version << std::endl;
        }
    }
    
    private:
    string m_cpu;
    string m_memory;
    string m_storage;
    string m_version;
    
};

// builder interface, concrete builder

class Builder
{
    public:
    virtual void buildCPU(const string& cpu) = 0;
    virtual void buildMemory(const string& mem) = 0;
    virtual void buildStorage(const string& sto) = 0;
    virtual void buildVersion(const string& ver) {};
    virtual Computer getProduct() = 0;

};

class MacBookBuilder : public Builder
{
    public:
    MacBookBuilder()
    {
        mac = Computer();
    }
    void buildCPU(const string& cpu) override
    {
        mac.setCPU(cpu);
    }
    void buildMemory(const string& mem) override
    {
        mac.setMemory(mem);
    }
    void buildStorage(const string& sto) override
    {
        mac.setStorage(sto);
    }
    void buildVersion(const string& ver) override
    {
        mac.setVersion(ver);
    }
    Computer getProduct() override
    {
        return mac;
    }
    
    private:
    Computer mac;
    
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
        //builder.buildVersion("Air");
        return builder.getProduct();
    }
    
    Computer assembelMacbook(Builder& builder)
    {
        builder.buildCPU("M3");
        builder.buildMemory("32GB");
        builder.buildStorage("1TB SSD");
        builder.buildVersion("Air");
        return builder.getProduct();
    }
};


int main() {
    ComputerAssembler computerAssembler;
    DesktopComputerBuilder builder;
    Computer computer = computerAssembler.assembelComputer(builder);
    
    std::cout << "My Desktop configuration: \n";
    computer.display();
    
    std::cout << "\n \n";
    
    MacBookBuilder macBookBuilder;
    Computer macComputer = computerAssembler.assembelMacbook(macBookBuilder);
    std::cout << "My Macbook configuration: \n";
    macComputer.display();
    
    return 0;
}