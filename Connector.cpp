/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "Connector.h"

Connector::Connector(std::string source) : source(source)
{
}

std::string Connector::getSource()
{
    return source;
}

Connector::~Connector()
{
}