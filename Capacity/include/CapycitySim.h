#ifndef CAPYCITYSIM_H
#define CAPYCITYSIM_H
#include "Blueprint.h"
#include <list>
class CapycitySim
{
    public:
        CapycitySim();
        ~CapycitySim();
        void print(){currentBlueprint->print();}
        void printall();
        void newBuilding(char todo){currentBlueprint->newBuilding(todo);}
        void newPlan();
        void deleteduplicatePlan(Blueprint* myblueprint);
        void planMenue();

    protected:

    private:
        int CurrentPlanNum;
        Blueprint* currentBlueprint;
        std::list<Blueprint*> Blueprintset;//named set as it should not contain duplicates


};

#endif // CAPYCITYSIM_H
