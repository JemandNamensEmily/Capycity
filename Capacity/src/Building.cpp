#include "Building.h"
#include <iostream>

#ifndef StandardMaterials
#define StandardMaterials
Material* StandardHolz = (Material*)new Holz();
Material* StandardMetall = (Material*)new Metall();
Material* StandardKunststoff = (Material*)new Kunststoff();
#endif

Building::Building()
{
    //ctor
    //default to empty
    Label = 'f';
    Grundpreis = 0;
    name = "Empty";
    spots = 0;
}
void Building::initMaterials(int HolzAm, int MetallAm, int KunststoffAm){
    materialmap[StandardHolz]= HolzAm;
    materialmap[StandardMetall]= MetallAm;
    materialmap[StandardKunststoff]=KunststoffAm;
}
void Building::print(){
    std::cout<<name<<": Preis: "<<GetPrice()<<std::endl;
    std::cout<<"Materials: ";
    for(auto& [key,value] : materialmap){
        std::cout<< value*spots<<": "<< key->Getname() <<"  ";
    }
    std::cout<<std::endl;
}
int Building::GetPrice(){
    int price = 0;
    for(auto& [key,value] : materialmap){
        price+=key->Getprice()*value;
    }
    price = price*spots;
    price = price + Grundpreis;
    return price;
}
Wasserkraftwerk::Wasserkraftwerk(int num){
    Grundpreis = 50;
    Label = 'a';
    name = "Wasserkraftwerk "+std::to_string(num);
    spots = 0;
    initMaterials(1,1,0);

}
Windkraftwerk::Windkraftwerk(int num){
    Grundpreis = 60;
    Label = 'i';
    name = "Windkraftwerk "+std::to_string(num);
    spots = 0;
    initMaterials(0,2,0);
}
Solarpanel::Solarpanel(int num){
    Grundpreis = 70;
    Label = 's';
    name = "Solarpanel "+std::to_string(num);
    spots = 0;
    initMaterials(0,1,1);
}
Building::~Building()
{
    //dtor
    for(auto& [key,value]: materialmap){
        if(key!=StandardHolz&&key!=StandardKunststoff&&key!=StandardMetall){
            delete key;
        }
    }
}
