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
    void buildDriver() {
        if (rand()%2 > 0)
            tr->transDriver = "TaxiDriver";
        else
            tr->transDriver = "BusDriver";
    }
    virtual int isReady() = 0;
    
    virtual Transport* getTransport() { return tr; }
};
