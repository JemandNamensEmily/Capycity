#ifndef BLUEPRINT_H
#define BLUEPRINT_H
#include "Building.h"
#include <set>

class Blueprint
{
    public:
        Blueprint(int len, int width, int kenn);
        ~Blueprint();
        void print();
        void newBuilding(char todo);

        int GetB() { return B; }
        int GetL() { return L; }
        Building*** GetArea(){return area;}
        int GetPlanNum(){return PlanNum;};

        bool operator()(Blueprint& Otherprint)const;
        std::set<Building*> GetUniqueBuildings();
        float calculateKennzahl();

    protected:

    private:
        int PlanNum;
        int B;
        int L;
        int Wasserkraftwerke;
        int Windkraftwerke;
        int Solarpanele;
        Building*** area;
};

#endif // BLUEPRINT_H
