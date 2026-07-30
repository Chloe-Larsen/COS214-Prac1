#include "ConnectorFactory.h"

ConnectorFactory::~ConnectorFactory()
{
}

Connector *PostgresFactory::createConnector()
{
    return new PostgresConnector();
}

Connector *RestApiFactory::createConnector()
{
    return new RestApiConnector();
}

Connector *CsvFactory::createConnector()
{
    return new CsvConnector();
}