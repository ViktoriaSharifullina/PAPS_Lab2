#pragma once
#include <iostream>
#include "Transport.cpp"

class TransportBuilder
{
protected:
    Transport* tr;
public:

    TransportBuilder() : tr(0) {}
    virtual ~TransportBuilder() {}

    virtual void createTransport() { tr = new Transport(); }
    virtual void buildGrownUp() {}
    virtual void buildChild() {}
    virtual void buildBeneficiary() {}
    virtual void buildChairs() {}
    virtual void buildDriver(){}
    virtual void buildPassangers(){}
    virtual void buildPrice(){}
    virtual int isReady() = 0;
    
    virtual Transport* getTransport() { return tr; }
};
