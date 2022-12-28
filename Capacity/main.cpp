#include <iostream>
#include "CapycitySim.h"

using namespace std;
//building types
int main()
{
    cout << "Capacity Builder" << endl;
    //get area size
    cout<<"How wide is your area? ";
    int width;
    do{
        cin>>width;
    }while(width<=0);

    cout<<"How long is it? ";
    int len;
    do{
        cin>>len;
    }while(len<=0);

    CapycitySim myCity = CapycitySim(len,width);
    char todo;
    do{
        cout<<"What would you like to do? P-Print, Q-Quit, N-New Building, C-Clear Area: ";
        cin >>todo;
        todo = toupper(todo);
        switch(todo){
        case 'P':
            myCity.print();
            break;
        case 'N': case 'C':
            myCity.newBuilding(todo);
        }

    }while(todo!='Q');

    return 0;
}
