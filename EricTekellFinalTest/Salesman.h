#include "Employee.h"

#ifndef SALESMAN_H
#define SALESMAN_H

class Salesman:public Employee {
public:
    double base;
    double commissionRate;
    double totalSales;
    Salesman();
    Salesman(string name, double gross, double taxPaid, double net, double base, double commissionRate, double totalSales);
    void display();
    void calcPay();
    Salesman(const Salesman& orig);
    virtual ~Salesman();
private:

};

#endif /* SALESMAN_H */

