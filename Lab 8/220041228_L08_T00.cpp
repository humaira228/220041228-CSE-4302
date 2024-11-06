
#include<bits/stdc++.h>
using namespace std;




class Maintenance {
public:
    void performMaintenance(const string& vehicleType) const {
        cout << vehicleType << " - Maintenance." << endl;
    }
};

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimitKg;

public:
    Vehicle(const string& plate, const string& maker, double limit)
        : licensePlate(plate), manufacturer(maker), carriageSizeLimitKg(limit) {}
};

class GasolineVehicle : public Vehicle {
    Maintenance maintenance;
    double fuelTankCapacityLiters;
    string fuelType;

public:
    GasolineVehicle(const string& plate, const string& maker, double limit, double tankCapacity, const string& fuel)
        : Vehicle(plate, maker, limit), fuelTankCapacityLiters(tankCapacity), fuelType(fuel) {}

    void performMaintenance() const {
        maintenance.performMaintenance("Gasoline Vehicle");
    }
};

class ElectricVehicle : public Vehicle {
    Maintenance maintenance;
    double batteryCapacityKWh;
    int chargingTimeMinutes;

public:
    ElectricVehicle(const string& plate, const string& maker, double limit, double battery, int chargeTime)
        : Vehicle(plate, maker, limit), batteryCapacityKWh(battery), chargingTimeMinutes(chargeTime) {}

    void performMaintenance() const {
        maintenance.performMaintenance("Electric Vehicle");
    }
};



class HybridVehicle : public Vehicle {
    Maintenance maintenance;
    double fuelTankCapacityLiters;
    string fuelType;
    double batteryCapacityKWh;
    double energyRegenerationEfficiency;

public:
    HybridVehicle(const string& plate, const string& maker, double limit, double tankCapacity, const string& fuel,
                  double battery, double regenEfficiency)
        : Vehicle(plate, maker, limit), fuelTankCapacityLiters(tankCapacity), fuelType(fuel),
          batteryCapacityKWh(battery), energyRegenerationEfficiency(regenEfficiency) {}

    void performMaintenance() const {
        maintenance.performMaintenance("Hybrid Vehicle");
    }
};

class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(const string& plate, const string& manf, double limit, double tankCapacity, const string& fuel)
        : GasolineVehicle(plate, manf, limit, tankCapacity, fuel) {}

    void performMaintenance() const {
        GasolineVehicle::performMaintenance();
    }
};

class Car : public GasolineVehicle {
private:
    int passengerCapacity;

public:
    Car(const string& plate, const string& manf, double limit, double tankCapacity, const string& fuel, int passengers)
        : GasolineVehicle(plate, manf, limit, tankCapacity, fuel), passengerCapacity(passengers) {}

    void performMaintenance() const {
        GasolineVehicle::performMaintenance();
    }
};

class Truck : public GasolineVehicle {
private:
    double cargoCapacityKg;

public:
    Truck(const string& plate, const string& manf, double limit, double tankCapacity, const string& fuel, double cargo)
        : GasolineVehicle(plate, manf, limit, tankCapacity, fuel), cargoCapacityKg(cargo) {}

    void performMaintenance() const {
        GasolineVehicle::performMaintenance();
    }
};

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& empName, int empId) : name(empName), id(empId) {}

    void introduce() const {
        cout << name << endl;
    }
};

class Manager : public Employee {
public:
    Manager(const string& empName, int empId) : Employee(empName, empId) {}

    void introduce() const {
        cout << "Mr. " << name << endl;
    }
};

class Driver : public Employee {
public:
    Driver(const string& empName, int empId) : Employee(empName, empId) {}

    void introduce() const {
        cout << name << endl;
    }
};

class Branch {
private:
    vector<Motorcycle> motorcycles;
    vector<Car> cars;
    vector<Truck> trucks;
    vector<ElectricVehicle> electricVehicles;
    vector<HybridVehicle> hybridVehicles;
    vector<Manager> managers;
    vector<Driver> drivers;

public:
    Branch() {}

    void addMotorcycle(const Motorcycle& motorcycle) {
        motorcycles.push_back(motorcycle);
    }

    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void addTruck(const Truck& truck) {
        trucks.push_back(truck);
    }

    void addElectricVehicle(const ElectricVehicle& ev) {
        electricVehicles.push_back(ev);
    }

    void addHybridVehicle(const HybridVehicle& hv) {
        hybridVehicles.push_back(hv);
    }

    void addManager(const Manager& manager) {
        managers.push_back(manager);
    }

    void addDriver(const Driver& driver) {
        drivers.push_back(driver);
    }

    void introduceEmployees() const {
        for (const auto& manager : managers) {
            manager.introduce();
        }
        for (const auto& driver : drivers) {
            driver.introduce();
        }
    }

    void performMaintenanceOnVehicles() const {
        for (const auto& motorcycle : motorcycles) {
            motorcycle.performMaintenance();
        }
        for (const auto& car : cars) {
            car.performMaintenance();
        }
        for (const auto& truck : trucks) {
            truck.performMaintenance();
        }
        for (const auto& ev : electricVehicles) {
            ev.performMaintenance();
        }
        for (const auto& hv : hybridVehicles) {
            hv.performMaintenance();
        }
    }
};

int main() {
    Branch branch;

    for (int i = 0; i < 5; ++i) {
        Motorcycle moto("MtorCycle" , "Honda", 150.0, 10.0, "petrol");
        branch.addMotorcycle(moto);

        Car car("Car"  , "Lamborghini", 500.0, 50.0, "petrol", 4);
        branch.addCar(car);

        Truck truck("Truck" , "Md", 3000.0, 200.0, "diesel", 5000.0);
        branch.addTruck(truck);

        ElectricVehicle ev("ElectricVehicle"  , "Tesla", 1000.0, 75.0, 120);
    }

        Manager m1("Armin" ,  1);
        branch.addManager(m1);
        Manager m2("Edison" ,  2);
        branch.addManager(m2);


            int driverId = 1;
            Driver d1("Ryan" , driverId);
            branch.addDriver(d1);



    cout << "Employees:" << endl;
    branch.introduceEmployees();


    branch.performMaintenanceOnVehicles();

    return 0;
}
