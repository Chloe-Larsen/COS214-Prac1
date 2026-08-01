#ifndef RESTAPIFACTORY_H
#define RESTAPIFACTORY_H

#include "Connector.h"
#include "ConnectorFactory.h"

class RestApiFactory : public ConnectorFactory
{
public:
    Connector *createConnector();
};

#endif
