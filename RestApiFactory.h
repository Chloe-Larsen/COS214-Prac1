/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef RESTAPIFACTORY_H
#define RESTAPIFACTORY_H

#include "Connector.h"
#include "ConnectorFactory.h"
#include "RestApiConnector.h"

class RestApiFactory : public ConnectorFactory
{
public:
    Connector *createConnector();
};

#endif
