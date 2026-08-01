/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef POSTGRESFACTORY_H
#define POSTGRESFACTORY_H

#include "Connector.h"
#include "ConnectorFactory.h"
#include "PostgresConnector.h"

class PostgresFactory : public ConnectorFactory
{
public:
    Connector *createConnector();
};

#endif