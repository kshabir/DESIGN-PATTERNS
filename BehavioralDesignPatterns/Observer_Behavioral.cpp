#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Observer Interface
class Observer
{
    public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Concrete Observer
class Display : public Observer
{
    public:
    void update(float temperature, float humidity, float pressure) 
    {
        std::cout << ": Temperature = " << temperature
                  << "°C, Humidity = " << humidity
                  << "%, Pressure = " << pressure << " hPa"
                  << std::endl;
    }
};

// Subject
// Concrete Subject
class WeatherStation
{
    public:
    // Some methods
    void registerObserver(Observer* observer)
    {
        Observers.push_back(observer);
    }
    void removeObserver(Observer* toRemove)
    {
        auto it = find(Observers.begin(), Observers.end(), toRemove);
        if (it != Observers.end()) 
        {
        Observers.erase(it);
        }
        else
        {
            cout << "Incorrect observer given!! \n";
        }
        
    }
    void setMeasurements(float tmp, float hum, float p)
    {
        this->temperature = tmp;
        this->humidity = hum;
        this->pressure = p;
        notifyObservers();
    }
    
    private:
    float temperature;
    float humidity;
    float pressure;
    
    vector<Observer*> Observers; 
    void notifyObservers()
    {
        int count = 0;
        for(auto* observer : Observers)
        {
            cout << "Observer " << ++count;
            observer->update(temperature, humidity, pressure);
        }
    }
};

int main() {
    WeatherStation weatherStation;
    
    Display observer1;
    Display observer2;
    Display observer3;
    Display observer4;
    
    weatherStation.registerObserver(&observer1);
    weatherStation.registerObserver(&observer2);
    weatherStation.registerObserver(&observer3);
    weatherStation.registerObserver(&observer4);
    
    weatherStation.removeObserver(&observer3);
    
    weatherStation.setMeasurements(25.5, 60, 1013.2);
    cout << "\n";
    weatherStation.setMeasurements(24.8, 58, 1014.5);

    return 0;
}