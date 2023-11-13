#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    int employeeID;

    Employee(std::string name, int employeeID) : name(name), employeeID(employeeID) {}

    virtual void getInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
    }
};

class FullTimeEmployee : public virtual Employee {
public:
    float salary;

    FullTimeEmployee(std::string name, int employeeID, float salary) : Employee(name, employeeID), salary(salary) {}

    void getInfo() const override {
        Employee::getInfo();
        std::cout << "Salary: $" << salary << std::endl;
    }
};

class PartTimeEmployee : public virtual Employee {
public:
    float hourlyWage;
    float hoursWorked;

    PartTimeEmployee(std::string name, int employeeID, float hourlyWage, float hoursWorked) 
        : Employee(name, employeeID), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

    void getInfo() const override {
        Employee::getInfo();
        std::cout << "Hourly Wage: $" << hourlyWage << std::endl;
        std::cout << "Hours Worked: " << hoursWorked << " hours" << std::endl;
    }
};

int main() {
    FullTimeEmployee fullTimeEmp("Baba Al-amin Salihu", 12345, 50000.0);
    PartTimeEmployee partTimeEmp("Misheal Ekene", 67890, 15.0, 20.0);

    std::cout << "Full-Time Employee Details:" << std::endl;
    fullTimeEmp.getInfo();
    std::cout << std::endl;

    std::cout << "Part-Time Employee Details:" << std::endl;
    partTimeEmp.getInfo();

    return 0;
}