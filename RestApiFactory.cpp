/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "RestApiFactory.h"

Connector *RestApiFactory::createConnector()
{
    return new RestApiConnector();
}