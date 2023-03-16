#pragma once
#include "TransportBuilder.cpp"
#include <string>
#include <typeinfo>

// Фабрика для автобуса

class BusTransportBuilder : public TransportBuilder
{
private:
    int passAmount;
    int _driver;
    int passCup = 30;
public:
    BusTransportBuilder() {
        passAmount = 0;
        _driver = 0;
    }

    int isReady() {
        return ((passAmount == passCup) && (_driver));
    }

    void createTransport() { tr = new Transport; }
    void buildGrownUp() { 
        for (int i = 0; i < rand() % 20; i++) {
            tr->vg.push_back(GrownUp());
            passAmount = +1;
        }
            
            
    }
    void buildChild() {
        for (int i = 0; i < rand() % 5; i++) {
            tr->vch.push_back(Child());
            passAmount = +1;
        }
    }
    void buildBeneficiary() {
        for (int i = 0; i < rand() % 10; i++) {
            tr->vb.push_back(Beneficiary());
            passAmount = +1;
        }          
    }
   
	
};
