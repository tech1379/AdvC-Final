#include <iostream>
#include <iomanip>

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
    string name;
    double gross;
    double taxPaid;
    double net;
    virtual void calcPay();
    virtual void display();
    Employee();
    Employee(string name, double gross, double taxPaid, double net);
    Employee(const Employee& orig);
    virtual ~Employee();
private:

};

#endif /* EMPLOYEE_H */

