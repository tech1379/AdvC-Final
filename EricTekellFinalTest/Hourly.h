#include "Employee.h"

#ifndef HOURLY_H
#define HOURLY_H

class Hourly:public Employee {
public:
    double rate;
    double hours;
    void calcPay();
    void display();
    Hourly();
    Hourly(string name, double gross, double taxPaid, double net, double rate, double hours);
    Hourly(const Hourly& orig);
    virtual ~Hourly();
private:

};

#endif /* HOURLY_H */

