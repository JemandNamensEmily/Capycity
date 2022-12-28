#include "Building.h"
#include <iostream>

Building::Building()
{
    //ctor
    //default to empty
    Label = 'f';
    Grundpreis = 0;
    name = "Empty";
    spots = 0;
}
void Building::print(){
    std::cout<<name<<": Preis: "<<GetPrice()<<std::endl;
    std::cout<<"Materials: "<<spots<<"x ( ";
    for(auto k:Materials){
        std::cout<<k->Getname()<<", ";
    }
    std::cout<<")"<<std::endl;
}
int Building::GetPrice(){
    int price = 0;
    for(auto k:Materials){
        price+=k->Getprice();
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
    Materials.push_back((Material*)new Holz());
    Materials.push_back((Material*)new Metall());

}
Windkraftwerk::Windkraftwerk(int num){
    Grundpreis = 60;
    Label = 'i';
    name = "Windkraftwerk "+std::to_string(num);
    spots = 0;
    Materials.push_back((Material*)new Metall());
    Materials.push_back((Material*)new Metall());
}
Solarpanel::Solarpanel(int num){
    Grundpreis = 70;
    Label = 's';
    name = "Solarpanel "+std::to_string(num);
    spots = 0;
    Materials.push_back((Material*)new Metall());
    Materials.push_back((Material*)new Kunststoff());
}
Building::~Building()
{
    //dtor
    for(auto k:Materials){delete k;}
}
