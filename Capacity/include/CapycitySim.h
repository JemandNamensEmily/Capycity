#ifndef CAPYCITYSIM_H
#define CAPYCITYSIM_H
#include "Building.h"
#include <set>

class CapycitySim
{
    public:
        CapycitySim(int len, int width);
        ~CapycitySim();
        void print();
        void newBuilding(char todo);
        int GetB() { return B; }
        int GetL() { return L; }

    protected:

    private:
        int B;
        int L;
        int Wasserkraftwerke;
        int Windkraftwerke;
        int Solarpanele;
        Building*** area;
};

#endif // CAPYCITYSIM_H
