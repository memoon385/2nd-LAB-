#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
private:
    string name;
    double fixedSalary;

public:
    FullTimeEmployee(const string& name, double salary) : name(name), fixedSalary(salary) {}

    double calculateSalary() const override {
        return fixedSalary;
    }

    void printDetails() const {
        cout << "Full-Time Employee: " << name << ", Salary: " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    string name;
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(const string& name, double rate, int hours)
        : name(name), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void printDetails() const {
        cout << "Part-Time Employee: " << name << ", Salary: " << calculateSalary() << endl;
    }
};

int main() {

    FullTimeEmployee fullTime("Ali", 5000);
    fullTime.printDetails();


    PartTimeEmployee partTime("Hassan", 20, 80);
    partTime.printDetails();

    return 0;
}