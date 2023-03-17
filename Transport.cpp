#pragma once
#include <iostream>
#include <vector>
#include "GrownUp.cpp"
#include "Child.cpp"
#include "Beneficiary.cpp"

//класс транспорт содержащий все типы пассажиров
class Transport
{
public:
    std::vector<GrownUp> vg;
    std::vector<Child> vch;
    std::vector<Beneficiary> vb;
    std::string transDriver;
    int price;
    
    void info() {
        int i;
        for (i = 0; i < vg.size(); ++i)  vg[i].info();
        for (i = 0; i < vch.size(); ++i)  vch[i].info();
        for (i = 0; i < vb.size(); ++i)  vb[i].info();
        std::cout << "Driver -> " << transDriver << "\n";   
    }
};
