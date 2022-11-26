#include <iostream>

using namespace std;
//building types
enum buildingtype{Frei = 'f', Wasserkraftwerk = 'a',Windkraftwerk = 'i',Solarpanel = 's',Error = 'e'};
buildingtype chartobuilding(char charin);
int main()
{
    cout << "Capacity Builder" << endl;


    //get area size
    cout<<"How wide is your area? ";
    int B;
    cin>>B;
    cout<<"How long is it? ";
    int L;
    cin>>L;
    //make area
    buildingtype** area= new buildingtype*[L];
    for(int l = 0; l<L; l++){
        area[l]= new buildingtype[B];
    }
    //init array
    for(int l=0; l<L; l++){
        for(int b=0; b<B; b++){
            area[l][b]=Frei;
        }
    }
    char todo;
    do{
        cout<<"What would you like to do? P-Print, Q-Quit, N-New Building, C-Clear Area: ";
        cin >>todo;
        todo = toupper(todo);
        switch(todo){
        case 'P':
            //print array
            for(int l=0; l<L; l++){
                for(int b=0; b<B; b++){
                    cout<<(char)area[l][b]<<" ";
                }
                cout << endl;
            }
            break;
        case 'N': case 'C':
            //get size
            int len;
            int wid;
            cout<<"Enter Width: ";
            cin >>wid;
            cout<<"Enter Length: ";
            cin >>len;
            //get position
            int posx;
            int posy;
            cout<<"Enter Position of upper left corner: "<<endl;
            cout<< "x: ";
            cin >>posx;
            posx = posx-1;//start at 1
            cout<<"y: ";
            cin>>posy;
            posy = posy-1;//start at 1


            //check for trouble
            bool areabound = false;
            bool buildcol = false;
            for(int w = posx; w<wid+posx; w++){
                    if(w<0 ||w>=B) areabound = true;
                for(int l=posy; l<len+posy; l++){
                    if(l<0 ||l>=L) areabound = true;
                    if(!areabound && todo !='C'){ //do not question if outside array or clearing area
                        if(area[l][w]!='f') buildcol=true;
                    }
                }
            }
            if(areabound || buildcol){
                cout<<"The Building could not be placed."<<endl;
                if(areabound){
                    cout<<"It is not fully in the building area."<<endl;
                }
                if(buildcol){
                    cout<<"It collides with other buildings."<<endl;
                }
            }
            else{
                //get buildingtype
                buildingtype newbuildingtype;
                if(todo=='C'){
                    newbuildingtype=Frei;
                }
                else{
                    do{
                        cout<<"Building Type (Wasserkraftwerk = a,Windkraftwerk = i,Solarpanel = s): ";
                        char readchar;
                        cin >> readchar;
                        newbuildingtype = chartobuilding(readchar);
                    }while(newbuildingtype==Error);

                }
                for(int w = posx; w<wid+posx; w++){
                    for(int l=posy; l<len+posy; l++){
                        area[l][w]=newbuildingtype;
                    }
                }
            }

        }

    }while(todo!='Q');



    //delete area
    for(int l=0; l<L; l++){
        delete[] area[l];
    }
    delete[] area;
    return 0;
}
buildingtype chartobuilding(char charin){
    //buildingtype{Frei = 'f', Wasserkraftwerk = 'a',Windkraftwerk = 'i',Solarpanel = 's', Error = 'e'};
    switch(charin){
    case 'f':
        return Frei;
    case 'a':
        return Wasserkraftwerk;
    case 'i':
        return Windkraftwerk;
    case 's':
        return Solarpanel;
    }
    return Error;
}
