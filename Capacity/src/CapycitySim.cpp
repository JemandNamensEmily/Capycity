#include "CapycitySim.h"
#include <iostream>
#include <set>
using namespace std;
    #ifndef EMPTYLOT
    #define EMPTYLOT
    Building* emptyLot = new Building();
    #endif
CapycitySim::CapycitySim(int len, int width)
{
    //ctor
    L=len;
    B=width;
    //make area
    area = new Building**[L];
    for(int l = 0; l<L; l++){
        area[l]= new Building*[B];
        for(int b=0;b<B;b++){
            //init Buildings
            area[l][b]=emptyLot;
        }

    }
    //init number of Buildings
    Solarpanele= 0;
    Wasserkraftwerke = 0;
    Windkraftwerke = 0;
}

CapycitySim::~CapycitySim()
{
    //dtor
    //delete area
   //create Set of all unique Buildings -> don't try to delete anything twice
    set<Building*> buildinglist;
    for(int l=0; l<L; l++){
        for(int b=0; b<B; b++){
            if(area[l][b]!=emptyLot){
                    //only add Buildings not already listet done by using set
                    buildinglist.insert(area[l][b]);
            }
        }
        delete[] area[l];
    }
    for(auto k:buildinglist){delete k;}
    delete[] area;
}

void CapycitySim::print(){
    //print array
    cout<<"Area map:"<<endl;
            for(int l=0; l<L; l++){
                for(int b=0; b<B; b++){
                    cout<<area[l][b]->GetLabel()<<" ";
                }
                cout << endl;
            }
    //create Set of all unique Buildings
    set<Building*> buildinglist;
    for(int l=0; l<L; l++){
        for(int b=0; b<B; b++){
            if(area[l][b]!=emptyLot){
                    //only add Buildings not already listet done by using set
                    buildinglist.insert(area[l][b]);
            }
        }
    }
    //print List of Buildings
    int total = 0; //Calculate Total Cost
    for(auto k:buildinglist){
            k->print();
            total+=k->GetPrice();
    }
    cout<<endl<<"Total: "<<total<<endl<<endl;
}
void CapycitySim::newBuilding(char todo){
    //get size
            int len;
            int wid;
            cout<<"Enter Width: ";
            do{
                cin >>wid;
            }while(wid<=0);
            cout<<"Enter Length: ";
            do{
               cin >>len;
            }while(len<=0);
            //get position
            int posx;
            int posy;
            cout<<"Enter Position of upper left corner: "<<endl;
            cout<< "x: ";
            do{
                cin >>posx;
            }while(posx<=0);
            posx = posx-1;//start at 1
            cout<<"y: ";
            do{
               cin>>posy;
            }while(posy<=0);
            posy = posy-1;//start at 1


            //check for trouble
            bool areabound = false;
            bool buildcol = false;
            for(int w = posx; w<wid+posx; w++){
                    if(w<0 ||w>=B) areabound = true;
                for(int l=posy; l<len+posy; l++){
                    if(l<0 ||l>=L) areabound = true;
                    if(!areabound && todo !='C'){ //do not question if outside array or clearing area
                        if(area[l][w]->GetLabel()!='f') buildcol=true;
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
                Building* NewBuilding = emptyLot;
                if(todo=='C'){
                    //Clear, leave NewBuilding = emptyLot;
                }
                else{
                    char readchar;
                    do{
                        cout<<"Building Type (Wasserkraftwerk = a,Windkraftwerk = i,Solarpanel = s): ";

                        cin >> readchar;
                        if(readchar=='a'){
                            Wasserkraftwerke+=1;
                            NewBuilding = new Wasserkraftwerk(Wasserkraftwerke);
                        }
                        if(readchar=='i'){
                            Windkraftwerke+=1;
                            NewBuilding = new Windkraftwerk(Windkraftwerke);
                        }
                        if(readchar=='s'){
                            Solarpanele+=1;
                            NewBuilding = new Solarpanel(Solarpanele);
                        }

                    }while(NewBuilding==emptyLot);

                }
                //set buildings in array
                for(int w = posx; w<wid+posx; w++){
                    for(int l=posy; l<len+posy; l++){
                        //Count spots occupied by building
                        if(area[l][w]==emptyLot){
                            NewBuilding->spots++;
                        }
                        if(area[l][w]!=emptyLot){
                            area[l][w]->spots--;
                            //delete buildings with no spots occupied
                            if(area[l][w]->spots<=0){
                                delete &area[l][w];
                            }
                        }
                        area[l][w]= NewBuilding;

                    }
                }
            }

}
