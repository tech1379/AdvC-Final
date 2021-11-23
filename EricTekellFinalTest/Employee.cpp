

#include "Employee.h"

Employee::Employee() {
    name = "";
    gross = 0.0;
    taxPaid = 0.0;
    net = 0.0;
}
Employee::Employee(string name, double gross, double taxPaid, double net)
{
    this->name = name;
    this->gross = gross;
    this->taxPaid = taxPaid;
    this->net = net;
}
void Employee::display()
{
    cout << setprecision(2) << fixed << endl;
    cout << left << setw(10) << "\nName: " << setw(21) << right << name << endl;
    cout << left << setw(10) << "Gross: " << setw(13) << right << "$" << gross << endl;
    cout << left << setw(10) << "Tax Paid: " << setw(14)<< right << "$" << taxPaid << endl;
    cout <<  left << setw(10) << "Net: " << setw(13) << right <<"$" << net << endl;
}
void Employee::calcPay()
{
    
}
Employee::Employee(const Employee& orig) {
}

Employee::~Employee() {
}

