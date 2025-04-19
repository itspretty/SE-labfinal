#pragma once
#include <string>
#include <algorithm>
#include <memory>

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual std::string drive() const = 0;
};

class Car : public Vehicle {
public:
    std::string drive() const override {
        return "Car is manufactured";
    }
};

class Bike : public Vehicle {
public:
    std::string drive() const override {
        return "Bike is manufactured";
    }
};

class Truck : public Vehicle {
public:
    std::string drive() const override {
        return "Truck is manufactured";
    }
};

class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> createVehicle(const std::string& type) {
        std::string t = type;
        std::transform(t.begin(), t.end(), t.begin(), ::tolower);

        if (t == "car")   return std::make_unique<Car>();
        if (t == "bike")  return std::make_unique<Bike>();
        if (t == "truck") return std::make_unique<Truck>();

        return nullptr;
    }
};