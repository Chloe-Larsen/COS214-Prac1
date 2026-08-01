/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "CsvFactory.h"

Connector *CsvFactory::createConnector()
{
    return new CsvConnector();
}