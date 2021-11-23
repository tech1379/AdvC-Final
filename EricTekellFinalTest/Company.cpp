

#include "Company.h"
#include <fstream>
int Company::loadCount = 0; 
Company::Company() {
}
void Company::menu(int & menu)
{
    cout << '\n' << endl;
    cout << left << setw(30) << right << setw(20) << "Main Menu" << endl;
    cout << setw(36) << setfill('*') << "\n" << endl;
    cout << "1. Load Employees." << endl;
    cout << "2. Add Employee." << endl;
    cout << "3. Remove Employee." << endl;
    cout << "4. Display Employees." << endl;
    cout << "5. Calculate and Display Payroll." << endl;
    cout << "6. Write Paycheck." << endl;
    cout << "7. Read and Display Paycheck." << endl;
    cout << "8. Exit." << endl;
    cout << setw(36) << "\n" << endl;
    cout << "Please enter a menu number to proceed: " << endl;
    cin >> menu;
    while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5 && menu != 6 && menu != 7 && menu != 8)
    {
        cout << "Menu options are 1 - 8" << endl;
        cout << "Please enter a menu number to proceed: " << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> menu;
    }
    cout << setfill(' ') << "\n" << endl;
     if (menu == 1)
        {
         loadEmployees();
        }
        else if (menu == 2)
        {
            addEmployee();
        }
        else if (menu == 3)
        {
            remove();
        }
        else if (menu == 4)
        {
            i=0;
            display();
        }
        else if (menu == 5)
        {
            calcDisplayPayroll();
        }
        else if (menu == 6)
        {
            writePaycheck();
        }
        else if (menu == 7)
        {
            readPaycheck();
        }
        else if (menu == 8)
        {
            //delete the employees vector for memory management
            Company::~Company();
            cout << "It's been fun and this was long." << endl;
            exit(0);
                   
        }
}
void Company::loadEmployees()
{
    //so you can only load the current employees once
    if(loadCount < 1)
    {
ifstream readFile("employees.txt");
string line;
getline(readFile, line);
while(!readFile.eof())
{
    getline(readFile, line);
    if(line == "management")
    {
        Management *mgmt = new Management();
        getline(readFile, line);
        mgmt->name = line;
        getline(readFile, line);
        mgmt->salary = stod(line);
        mgmt->calcPay();
        employees.push_back(mgmt);
    }
    else if (line == "hourly")
    {
        Hourly *hourly = new Hourly();
        getline(readFile, line);
        hourly->name = line;
        getline(readFile, line);
        hourly->rate = stod(line);
        getline(readFile, line);
        hourly->hours = stod(line);
        employees.push_back(hourly);
    }
    else if (line == "salesman")
    {
        Salesman *sales = new Salesman();
        getline(readFile, line);
        sales->name = line;
        getline(readFile, line);
        sales->base = stod(line);
        getline(readFile, line);
        sales->commissionRate = stod(line);
        getline(readFile, line);
        sales->totalSales = stod(line);
        employees.push_back(sales);
    }
}
readFile.close();
loadCount++;
    }
    
    
}
void Company::addEmployee()
{
    string name;
    string type;
    double salary;
    double base;
    double commission;
    double total;
    double rate;
    double hour;
    try
    {
    cout << "Please enter the employee name: " << endl;
    cin.clear();
    cin.ignore();
    getline(cin, name);
    if (name == "")
    {
        throw 1;
    }
    }
    catch(int x)
    {
        if (x == 1)
        {
            cout << "You must enter an name." << endl;
            addEmployee();
        }
    }
    
    cout << "Please Employee type(Salesman, Management, or Hourly): " << endl;
    cin >> type;
    if (type == "management" || type == "Management" || type == "MANAGEMENT")
    {
        cout << "Please enter the salary: " << endl;
        cin >> salary;
        Management *mgmt = new Management();
        mgmt->name = name;
        mgmt->salary = salary;
         employees.push_back(mgmt);
        
    }
    else if (type == "SALESMAN" || type == "salesman" || type == "Salesman")
    {
        cout << "Please enter the base: " << endl;
        cin >> base;
        cout << "Please enter the Commission Rate as percentage (e.g. .25): " << endl;
        cin >> commission;
        cout << "Please enter the total sales: " << endl;
        cin >> total;
        Salesman *sales = new Salesman();
        sales->name = name;
        sales->base = base;
        sales->commissionRate = commission;
        sales->totalSales = total;
         employees.push_back(sales);
    }
    else if(type == "HOURLY" || type == "Hourly" || type == "hourly")
    {
        cout << "Please enter the rate: " << endl;
        cin >> rate;
        cout << "Please enter the hours: " << endl;
        cin >> hour;
        Hourly *hours = new Hourly();
        hours->name = name;
        hours->rate = rate;
        hours->hours = hour;
         employees.push_back(hours);
    }
    else
    {
        cout << "Input not correct. Try Again!" << endl;
        addEmployee();
    }
}
void Company::operator -=(int number)
{
    delete employees[number];
    employees.erase (employees.begin()+number);
}
void Company::remove()
{
    if (employees.empty())
    {
        cout << "Nothing to remove!" << endl;
        return;
    }
    for(int i = 0; i < employees.size(); i++)
{
    cout << "\n**********" << i << "**********" << endl;
    employees[i]->display();
}
    cout << "\n\n" << endl;
    cout << "Please enter a number to remove: " << endl;
    cin.clear();
    cin.ignore();
    cin >> number;
    *this -= number;
}
void Company::display()
{
    if (i < employees.size())
    {
    cout << employees[i]->name << endl;
    i++;
    display();
    }
}
void Company::writePaycheck()
{
    
     for(int i = 0; i < employees.size(); i++)
{
  
    cout << "**********" << i << "**********" << endl;
    employees[i]->display();
    cout << "\n\n" << endl;
}
     cout << "Please enter a number to write paycheck: " << endl;
    int number;
    cin >> number;
    if (number > employees.size())
    {
        cout << "Invalid Employee. Try Again!" << endl;
        writePaycheck();
        
    }
    ofstream out("paycheck.bin", ios::out | ios::binary);
    out.write((char*)&employees[number], sizeof(employees[number]));
    out.close();
}
void Company::readPaycheck()
{
    ifstream in("paycheck.bin", ios::in | ios::binary);
    if(in.read((char*)&mg, sizeof(mg)))
    {
        mg->display();
    }
    else if (in.read((char*)&sales, sizeof(sales)))
    {
        sales->display();
    }
    else if (in.read((char*)&hr, sizeof(hr)))
    {
        hr->display();
    }
    in.close();
}
void Company::calcDisplayPayroll()
{
    
    for(int i = 0; i < employees.size(); i++)
{
    employees[i]->calcPay();
    employees[i]->display();
}
}
Company::Company(const Company& orig) {
}

Company::~Company() {
   
    for(int i =0; i < employees.size(); i++)
{
    delete employees[i];
}
    employees.clear();
    delete mg;
    delete sales;
    delete hr;
}

