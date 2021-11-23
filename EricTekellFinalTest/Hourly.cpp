

#include "Hourly.h"

Hourly::Hourly() {
    rate = 0.0;
    hours = 0.0;
}
Hourly::Hourly(string name, double gross, double taxPaid, double net, double rate, double hours):Employee(name,gross,taxPaid,net)
{
    this->rate = rate;
    this->hours = hours;
}
void Hourly::display()
{
    Employee::display();
    cout << left << setw(10) << "Rate: " << setw(14)<< right << "$" << rate << endl;
    cout <<  left << setw(10) << "Hours: " << setw(19) << right << hours << endl;
    
    
}
void Hourly::calcPay()
{
    if(hours > 40)
    {
        gross = ((hours - 40) * rate * 1.5) + (40 * rate);
    }
    else
    {
        gross = rate * hours;
    }
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
Hourly::Hourly(const Hourly& orig) {
}

Hourly::~Hourly() {
}

