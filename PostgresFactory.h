#ifndef POSTGRESFACTORY_H
#define POSTGRESFACTORY_H

#include "Connector.h"
#include "ConnectorFactory.h"

class PostgresFactory : public ConnectorFactory
{
public:
    Connector *createConnector();
};

#endif