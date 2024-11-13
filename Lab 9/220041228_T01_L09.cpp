#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Vehicle
{
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit;

public:
    Vehicle(const string &licensePlate, const string &manufacturer, double carriageSizeLimit)
        : licensePlate(licensePlate), manufacturer(manufacturer), carriageSizeLimit(carriageSizeLimit) {}

    virtual void performMaintenance() = 0;

    double getCarriageSizeLimit() const { return carriageSizeLimit; }

    virtual void display() 
    {
        cout << "License Plate: " << licensePlate << ", Manufacturer: " << manufacturer
             << ", Carriage Size Limit: " << carriageSizeLimit << " kg\n";
    }
};

class GasolineVehicle : virtual public Vehicle
{
protected:
    double fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicle(const string &licensePlate, const string &manufacturer, double carriageSizeLimit,
                    double fuelTankCapacity, const string &fuelType)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          fuelTankCapacity(fuelTankCapacity), fuelType(fuelType) {}

    virtual double calculateFuelConsumption(double distance)
    {
        double consumptionRate = 10.0;
        return (consumptionRate / 100) * distance;
    }

     void performMaintenance()
    {
        cout << "Maintenance-GasolineVehicle" << endl;
    }

    void display() 
    {
        Vehicle::display();
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters, Fuel Type: " << fuelType << "\n";
    }
};

class ElectricVehicle : virtual public Vehicle
{
protected:
    double batteryCapacity;
    int chargingTime;

public:
    ElectricVehicle(const string &licensePlate, const string &manufacturer, double carriageSizeLimit,
                    double batteryCapacity, int chargingTime)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          batteryCapacity(batteryCapacity), chargingTime(chargingTime) {}

    virtual double electricityConsumption(double distance) = 0;

     void performMaintenance() 
    {
        cout << "Maintenance-ElectricVehicle";
    }

    virtual void display() 
    {
        Vehicle::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh, Charging Time: " << chargingTime << " minutes\n";
    }
};

class Motorcycle : public GasolineVehicle
{
public:
    Motorcycle(const string &licensePlate, const string &manufacturer, double carriageSizeLimit,
               double fuelTankCapacity, const string &fuelType)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit), GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType) {}

    double calculateFuelConsumption(double distance)
    {
        double consumptionRate = 5.0;
        return (consumptionRate / 100) * distance;
    }

    void performMaintenance() 
    {
        cout << "Motorcycle - maintenance.\n";
    }
};

class Car : public GasolineVehicle
{
    int passengerCapacity;

public:
    Car(const string &licensePlate, const string &manufacturer, double carriageSizeLimit,
        double fuelTankCapacity, const string &fuelType, int passengerCapacity)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit), GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          passengerCapacity(passengerCapacity) {}

    double calculateFuelConsumption(double distance)
    {
        double consumptionRate = 8.0;
        return (consumptionRate / 100) * distance;
    }

    void performMaintenance() override
    {
        cout << "Car -  maintenance.\n";
    }
};

class Truck : public GasolineVehicle
{
    double cargoCapacity;

public:
    Truck(const string &licensePlate, const string &manufacturer, double carriageSizeLimit,
          double fuelTankCapacity, const string &fuelType, double cargoCapacity)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit), GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          cargoCapacity(cargoCapacity) {}

    double calculateFuelConsumption(double distance)
    {
        double consumptionRate = 15.0;
        return (consumptionRate / 100) * distance;
    }

    void performMaintenance() override
    {
        cout << "Truck -  maintenance.\n";
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle
{
    double energyRegenerationEfficiency;

public:
    HybridVehicle(const string &licensePlate, const string &manufacturer, double carriageSizeLimit,
                  double fuelTankCapacity, const string &fuelType, double batteryCapacity, int chargingTime,
                  double energyRegenerationEfficiency)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          ElectricVehicle(licensePlate, manufacturer, carriageSizeLimit, batteryCapacity, chargingTime),
          energyRegenerationEfficiency(energyRegenerationEfficiency) {}

    void display()
    {
        Vehicle::display();
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters, Fuel Type: " << fuelType << "\n";
        cout << "Battery Capacity: " << batteryCapacity << " kWh, Charging Time: " << chargingTime << " minutes\n";
        cout << "Energy Regeneration Efficiency: " << energyRegenerationEfficiency * 100 << "%\n";
    }

    void performMaintenance() 
    {
        cout << "Hybrid Vehicle - maintenance.\n";
    }

    double calculateFuelConsumption(double distance)
    {
        double fuelConsumptionRate = 30.0;
        double electricityConsumptionRate = 13.0;
        return ((fuelConsumptionRate / 100) * distance +
                (electricityConsumptionRate / 100) * distance * energyRegenerationEfficiency);
    }
};

void sort_vehicles_by_capacity(Vehicle **vehicles, int n)
{
    std::sort(vehicles, vehicles + n, [](Vehicle *a, Vehicle *b)
              { return a->getCarriageSizeLimit() > b->getCarriageSizeLimit(); });
}

int main()
{
    Vehicle *vehicles[4];

    vehicles[0] = new Car("123", "Toyota", 1500.0, 50.0, "Petrol", 5);
    vehicles[1] = new Motorcycle("6y7", "Yamaha", 200.0, 15.0, "Petrol");
    vehicles[2] = new Truck("ht68", "Volvo", 10000.0, 300.0, "Diesel", 5000.0);
    vehicles[3] = new HybridVehicle("yxc", "Toyota Prius", 1600.0, 40.0, "Petrol", 50.0, 60, 0.8);

    for (int i = 0; i < 4; ++i)
    {
        vehicles[i]->display();
        cout << endl;
    }

    sort_vehicles_by_capacity(vehicles, 4);

    cout << "Sorted Vehicles:";
    for (int i = 0; i < 4; ++i)
    {
        vehicles[i]->display();
        cout << endl;
    }

    cout << "Performing maintenance:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        vehicles[i]->performMaintenance();
        cout << endl;
    }

    for (int i = 0; i < 4; ++i)
    {
        delete vehicles[i];
    }

    return 0;
}
