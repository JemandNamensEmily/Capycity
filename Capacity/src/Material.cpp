#include "Material.h"

Material::Material()
{
    //ctor
    //empty Material
    name = "empty";
    price = 0;
}

Material::~Material()
{
    //dtor
}

Holz::Holz(){
    name = "Holz";
    price = 1;
}
Metall::Metall(){
    name = "Metall";
    price = 2;
}
Kunststoff::Kunststoff(){
    name = "Kunststoff";
    price = 3;
}
