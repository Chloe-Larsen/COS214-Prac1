/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H

#include "Connector.h"

class PostgresConnector : public Connector
{
public:
    PostgresConnector();
    std::vector<std::string> extract() override;
};

#endif