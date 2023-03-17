#pragma once
#include "TransportBuilder.cpp"
#include <string>
#include <typeinfo>


// Фабрика для такси

class TaxiTransportBuilder : public TransportBuilder
{
private:
    int passAmount;
    int childAmount;
    int chairAmount;
    int _driver;
    int passCup = 4;
public:

    TaxiTransportBuilder() {
        passAmount = 0;
        childAmount = 0;
        _driver = 0;
    }

    int isReady() {
        try {
            if (tr->transDriver == "TaxiDriver") {
                if (chairAmount < childAmount) {
                    throw std::exception("There should be a seat for every child in taxi!\n");
                }
                else {
                    return ((passAmount == passCup) && (_driver));
                }
            }
            else return 0;
        }
        catch(std::exception &ex) {
            std::cout << "Error ->  " << ex.what();
        }
    }

    void buildPassangers() {
        try {
            for (int i = 0; i < 3; i++) {
                buildGrownUp();
            }
            for (int i = 0; i < 1; i++) {
                buildChild();
            }
            for (int i = 0; i < 1; i++) {
                buildChairs();
            }
        }
        catch (std::exception& ex) {
            std::cout << "Error ->  " << ex.what();
            std::cout << "The taxi should have no more than 4 passengers, now passengers: " << passAmount << "\n";
        }

    }

    void createTransport() { tr = new Transport; }

    void buildGrownUp() {
        passAmount += 1;
        if (passAmount < passCup + 1) {
            tr->vg.push_back(GrownUp());            
        }
        else {
            throw std::exception("Too many passengers, the taxi is full!\n");
        }
        
    }

    void buildChild() {
        passAmount += 1;
        childAmount += 1;
        if (passAmount < passCup + 1) {
            tr->vch.push_back(Child());   
        }
        else {
            throw std::exception("Too many passengers, the taxi is full!\n");
        }
        
    }
    
    void buildChairs() {
        chairAmount += 1;
    }

    void buildDriver() {
        _driver += 1;
        try {
            if (_driver < 2) {
                tr->transDriver = "TaxiDriver";
            }
            else {
                throw std::exception("The taxi already has a driver!\n");
            }
        }
        catch (std::exception& ex) {
            std::cout << "Error ->  " << ex.what();
        }
    }

    
};
