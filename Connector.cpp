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