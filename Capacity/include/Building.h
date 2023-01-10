#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <vector>
#include <map>
#include "Material.h"



class Building
{
    public:
        Building();
        ~Building();

        void print();
        int GetPrice();
        int GetGrundpreis() { return Grundpreis; }
        void SetGrundpreis(int val) { Grundpreis = val; }
        char GetLabel() { return Label; }
        void SetLabel(char val) { Label = val; }
        std::string GetName() { return name;}
        void SetName(std::string nam) { name = nam; }

        int spots;
    protected:
        int Grundpreis;
        char Label;
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
        Wasserkraftwerk(int num);

};
class Windkraftwerk : public Building
{
    public:
        Windkraftwerk(int num);

};
class Solarpanel: public Building
{
    public:
        Solarpanel(int num);
};

#endif // BUILDING_H
