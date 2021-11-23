#include "Hourly.h"
#include "Employee.h"
#include "Management.h"
#include "Salesman.h"
#include "Company.h"
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    Company c;
    int menu = 0;
    
    while(menu != 8)
    {
        c.menu(menu);
    }
    
    return 0;
}

