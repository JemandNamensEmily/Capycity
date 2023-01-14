#include <iostream>
#include "CapycitySim.h"

using namespace std;

int main()
{
    cout << "Capacity Builder" << endl;


    CapycitySim myCity = CapycitySim();
    char todo;
    do{
        cout<<"What would you like to do? P-Print, A-Print All, Q-Quit, N-New Building, C-Clear Area, M-Go to Plan Menue: ";
        cin >>todo;
        todo = toupper(todo);
        switch(todo){
        case 'A':
            myCity.printall();
            break;
        case 'P':
            myCity.print();
            break;
        case 'N': case 'C':
            myCity.newBuilding(todo);
            break;
        case 'M':
            myCity.planMenue();
        }

    }while(todo!='Q');

    return 0;
}
