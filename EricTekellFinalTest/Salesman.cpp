

#include "Salesman.h"

Salesman::Salesman() {
    base = 0.0;
    commissionRate = 0.0;
    totalSales = 0.0;
}
Salesman::Salesman(string name, double gross, double taxPaid, double net, double base, double commissionRate, double totalSales):Employee(name,gross,taxPaid,net)
{
    this->base = base;
    this->commissionRate = commissionRate;
    this->totalSales = totalSales;
}
void Salesman::calcPay()
{
    gross = base + (totalSales * commissionRate);
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
void Salesman::display()
{
    Employee::display();
    cout << left << setw(10) << "Base: " << setw(14)<< right << "$" << base << endl;
    cout <<  left << setw(10) << "Commission Rate: " << setw(13) << right << commissionRate << endl;
    cout <<  left << setw(10) << "Total Sales: " << setw(10) <<"$" << right << totalSales << endl;
    
}
Salesman::Salesman(const Salesman& orig) {
}

Salesman::~Salesman() {
}

