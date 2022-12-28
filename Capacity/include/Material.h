#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

class Material
{
    public:
        Material();
        virtual ~Material();

        std::string Getname() { return name; }
        void Setname(std::string val) { name = val; }
        int Getprice() { return price; }
        void Setprice(int val) { price = val; }

    protected:
        std::string name;
        int price;
    private:

};
class Holz : Material{
    public:
        Holz();
};
class Metall : Material{
    public:
        Metall();
};
class Kunststoff : Material{
    public:
        Kunststoff();
};
#endif // MATERIAL_H
