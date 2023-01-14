#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <vector>
#include <map>
#include "Material.h"



class Building
{
    public:
        Building();//makes empty building
        Building(std::string myName, char myLabel, int myGrundpreis, int myLeistung):name(myName), Label(myLabel),Grundpreis(myGrundpreis),Leistung(myLeistung),spots(0){}
        ~Building();

        void print();

        int GetPrice();//Full price (Grundpreis+Materialpreis)
        int GetGrundpreis() { return Grundpreis; }
        void SetGrundpreis(int val) { Grundpreis = val; }
        char GetLabel() { return Label; }
        void SetLabel(char val) { Label = val; }
        float GetLeistung(){return Leistung;}
        std::string GetName() { return name;}
        void SetName(std::string nam) { name = nam; }

        int spots;//How many squares does the building occupy
    protected:
        int Grundpreis;
        float Leistung;
        char Label; //to print in map
        std::string name;
        /*
            Ich habe die Verwaltung der Materialien hier umgesetzt,
            weil es unwahrscheinlich scheint das die Materialien für
            andere Dinge mit der gleichen Struktur verwaltet werden
            könnten, und mir eine zusätzliche Verwaltungsklasse
            unnötig umständlich erschien.
        */
        std::map<Material*,int> materialmap;
        void initMaterials(int HolzAm, int MetallAm, int KunststoffAm);
    private:

};

class Wasserkraftwerk : public Building
{
    public:
        Wasserkraftwerk(int num);//num added to label to differentiate buildings of same type

};
class Windkraftwerk : public Building
{
    public:
        Windkraftwerk(int num);//num added to label to differentiate buildings of same type

};
class Solarpanel: public Building
{
    public:
        Solarpanel(int num);//num added to label to differentiate buildings of same type
};

#endif // BUILDING_H
