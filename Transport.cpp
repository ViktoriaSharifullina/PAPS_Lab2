#include <iostream>
#include <vector>
#include "GrownUp.cpp"
#include "Child.cpp"
#include "Beneficiary.cpp"

class Transport
{
public:
    vector<GrownUp> vg;
    vector<Child> vch;
    vector<Beneficiary> vb;
    std::string transDriver;
    
    void info() {
        int i;
        for (i = 0; i < vg.size(); ++i)  vg[i].info();
        for (i = 0; i < vch.size(); ++i)  vch[i].info();
        for (i = 0; i < vb.size(); ++i)  vb[i].info();
       
    }
};
