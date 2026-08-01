/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H

#include "Connector.h"
#include "CsvConnector.h"

class CsvConnector : public Connector
{
public:
    CsvConnector();
    std::vector<std::string> extract();
};

#endif