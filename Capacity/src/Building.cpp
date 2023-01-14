#include "Building.h"
#include <iostream>

#ifndef StandardMaterials
#define StandardMaterials
//Standard Materials, so all Buildings can have the same ones(no copies)
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
    Leistung = 0;
}

void Building::initMaterials(int HolzAm, int MetallAm, int KunststoffAm){//Builds the materialmap of the building
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
//Inits of different Buildingtypes with static values and Materials to shorten adding buildings
Wasserkraftwerk::Wasserkraftwerk(int num): Building("Wasserkraftwerk "+std::to_string(num),'a',50,100){
    initMaterials(1,1,0);

}
Windkraftwerk::Windkraftwerk(int num): Building("Windkraftwerk "+std::to_string(num),'i',60,200){
    initMaterials(0,2,0);
}
Solarpanel::Solarpanel(int num):Building("Solarpanel "+std::to_string(num),'s',70,170){
    initMaterials(0,1,1);
}
Building::~Building()
{
    //dtor
    //std::cout<<"Deleting building "<<name<<std::endl;
    //delete non Standard Materials used for individual buildings
    for(auto& [key,value]: materialmap){
        if(key!=StandardHolz&&key!=StandardKunststoff&&key!=StandardMetall){
            delete key;
        }
    }
}
