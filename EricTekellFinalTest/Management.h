#include "Employee.h"

#ifndef MANAGEMENT_H
#define MANAGEMENT_H

class Management:public Employee {
public:
    double salary;
    Management();
    Management(string name, double gross, double taxPaid, double net, double salary);
    void calcPay();
    void display();
    Management(const Management& orig);
    virtual ~Management();
private:

};

#endif /* MANAGEMENT_H */

