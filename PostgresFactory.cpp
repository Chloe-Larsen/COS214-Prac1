/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "PostgresFactory.h"

Connector *PostgresFactory::createConnector()
{
    return new PostgresConnector();
}