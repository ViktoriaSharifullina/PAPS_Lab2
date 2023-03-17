#pragma once
#include "TransportBuilder.cpp";

class Director
{
public:
    Transport* createTransport(TransportBuilder& builder)
    {
        builder.createTransport();
        builder.buildDriver();
        builder.buildPassangers();
        builder.buildPrice();

        return(builder.getTransport());
    }
    
};