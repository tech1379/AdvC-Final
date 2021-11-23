

#include "Management.h"

Management::Management() {
    salary = 0.0;
}
Management::Management(string name, double gross, double taxPaid, double net, double salary):Employee(name,gross,taxPaid,net)
{
    this->salary = salary;
}
void Management::calcPay()
{
    gross = salary/52;
    if (gross < 1000)
    {
        taxPaid = gross * .12;
        net = gross - taxPaid;
    }
    else if(gross <= 2000)
    {
        taxPaid = gross * .14;
        net = gross - taxPaid;
    }
    else
    {
        taxPaid = gross * .19;
        net = gross - taxPaid;
    }
}
void Management::display()
{
    Employee::display();
    cout << left << setw(10) << "Salary: " << setw(12)<< right << "$" << salary << endl;
   
}
Management::Management(const Management& orig) {
}

Management::~Management() {
}

