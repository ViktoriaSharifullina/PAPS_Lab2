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
        if (tr->transDriver == "BusDriver") {
            return ((passAmount == passCup) && (_driver));
        }
        else {
            return 0;
        }
    }

    void createTransport() { tr = new Transport; }

    void buildGrownUp() {
        passAmount += 1;
        if (passAmount < 31) {
            tr->vg.push_back(GrownUp());      
        }
        else {
            throw std::exception("Too many passengers, the buss is full!\n");
        }  
    }

    void buildChild() {
        passAmount += 1;
        if (passAmount < 31) {
            tr->vch.push_back(Child());       
        }
        else {
            throw std::exception("Too many passengers, the buss is full!\n");
        }
    }

    void buildBeneficiary() {
        passAmount += 1;
        if (passAmount < 31) {
            tr->vb.push_back(Beneficiary());
        }
        else {
            throw std::exception("Too many passengers, the buss is full!\n");
        }
    }

    void buildPassangers() {
        try {
            for (int i = 0; i < 25; i++) {
                buildGrownUp();
            }
            for (int i = 0; i < 5; i++) {
                buildBeneficiary();
            }
            for (int i = 0; i < 5; i++) {
                buildChild();
            }
        }
        catch(std::exception &ex){
            std::cout << "Error ->  " << ex.what();
            std::cout << "The bus should have no more than 30 passengers, now passengers: " << passAmount << "\n";
        }
        
    }

    void buildDriver() {
        _driver += 1;
        try {
            if (_driver < 2) {
                tr->transDriver = "BusDriver";
            }
            else {
                throw std::exception("The bus already has a driver!\n");
            }
        }
        catch (std::exception& ex) {
            std::cout << "Error ->  " << ex.what();
        }
    }

    void buildPrice() {
        tr->price = tr->vg.size() * 25 + tr->vb.size() * 10 + tr->vch.size() * 5;
        std::cout << "Travel by bus will be paid for: " << tr->price << " rubles";
    }

};
