#include "Employee.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include "Management.h"
#include "Salesman.h"
#include "Hourly.h"

using namespace std;

#ifndef COMPANY_H
#define COMPANY_H

class Company {
public:
    static int loadCount;
    int i = 0;
    int number;
    Employee emp;
    vector <Employee *> employees;
    Management *mg = new Management();
    Salesman * sales = new Salesman();
    Hourly * hr = new Hourly();
    void menu(int &menu);
    void loadEmployees();
    void addEmployee();
    void remove();
    void operator -=(int number);
    void display();
    void writePaycheck();
    void readPaycheck();
    void calcDisplayPayroll();
    Company();
    Company(const Company& orig);
    virtual ~Company();
private:

};

#endif /* COMPANY_H */

