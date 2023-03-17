#include <iostream>;
#include "Director.cpp";
#include "TaxiTransportBuilder.cpp";
#include "BusTransportBuilder.cpp";

using namespace std;

int main()
{
    Director dir;
    TaxiTransportBuilder ttb;
    BusTransportBuilder btb;
    Transport* taxi = dir.createTransport(ttb);
    Transport* bus = dir.createTransport(btb);

    cout << "\n----TAXI----\n";
    taxi->info();
    if (ttb.isReady() == 0) {
        cout << "The taxi is not ready for departure\n";
    }
    else {
        cout << "The taxi is ready for departure\n";
    }
    
    cout << "----BUS----\n";
    bus->info();
    if (btb.isReady() == 0) {
        cout << "The bus is not ready for departure\n";
    }
    else {
        cout << "The bus is ready for departure\n";
    }
    
    return 0;
}
