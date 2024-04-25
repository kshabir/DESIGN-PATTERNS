#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

// Common interface for computer prototypes
class ComputerPrototype {
public:
    virtual std::unique_ptr<ComputerPrototype> clone() const = 0;
    virtual void displayConfig() const = 0;
    virtual void setRAM(const std::string& ram) {}
    virtual void setStorage(const std::string& storage) {}
};

// Concrete prototype for desktop computers
class DesktopComputer : public ComputerPrototype {
private:
    std::string cpu_;
    std::string ram_;
    std::string storage_;

public:
    DesktopComputer(const std::string& cpu, const std::string& ram, const std::string& storage)
        : cpu_(cpu), ram_(ram), storage_(storage) {}

    std::unique_ptr<ComputerPrototype> clone() const override {
        return std::make_unique<DesktopComputer>(*this);
    }
    void setRAM(const std::string& ram)
    {
        ram_ = ram;
    }
    void setStorage(const std::string& storage) {storage_ = storage; }

    void displayConfig() const override {
        std::cout << "Desktop Configuration:\n";
        std::cout << "CPU: " << cpu_ << "\n";
        std::cout << "RAM: " << ram_ << "\n";
        std::cout << "Storage: " << storage_ << "\n";
    }
};

// Concrete prototype for MacBooks
class MacBook : public ComputerPrototype {
private:
    std::string cpu_;
    std::string ram_;
    std::string storage_;
    std::string version_; // Unique to MacBook

public:
    MacBook(const std::string& cpu, const std::string& ram, const std::string& storage, const std::string& version)
        : cpu_(cpu), ram_(ram), storage_(storage), version_(version) {}

    std::unique_ptr<ComputerPrototype> clone() const override {
        return std::make_unique<MacBook>(*this);
    }
    
        void setRAM(const std::string& ram)
    {
        ram_ = ram;
    }
    void setStorage(const std::string& storage) {storage_ = storage; }

    void displayConfig() const override {
        std::cout << "MacBook Configuration:\n";
        std::cout << "CPU: " << cpu_ << "\n";
        std::cout << "RAM: " << ram_ << "\n";
        std::cout << "Storage: " << storage_ << "\n";
        std::cout << "Version: " << version_ << "\n";
    }
};

// Builder for customizing prototypes
class ComputerBuilder {
private:
    ComputerPrototype* prototype_;

public:
    ComputerBuilder(ComputerPrototype* prototype) : prototype_(prototype) {}

    void setCustomRAM(const std::string& ram) 
    {
        prototype_->setRAM(ram);
    }

    void setCustomStorage(const std::string& storage) 
    {
        prototype_->setStorage(storage);
    }

    // Add more customization methods as needed

    ComputerPrototype* getResult() {
        return prototype_;
    }
};

int main() {
    // Create prototypes
    auto desktopPrototype = std::make_unique<DesktopComputer>("Intel Core i7", "16GB DDR4", "1TB HDD");
    auto macBookPrototype = std::make_unique<MacBook>("Apple M1", "8GB LPDDR4X", "512GB SSD", "Pro 2024");

    // Customize prototypes using builder
    ComputerBuilder desktopBuilder(desktopPrototype.get());
    desktopBuilder.setCustomRAM("32GB DDR4");
    desktopBuilder.getResult();

    ComputerBuilder macBookBuilder(macBookPrototype.get());
    macBookBuilder.setCustomRAM("32GB LPDDR4X");
    macBookBuilder.getResult();

    // Display customized configurations
    desktopPrototype->displayConfig();
    macBookPrototype->displayConfig();

    return 0;
}
