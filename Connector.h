#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

class Connector
{
protected:
    std::string source;

public:
    Connector(std::string);
    virtual std::vector<std::string> extract() = 0;
    std::string getSource();
    virtual ~Connector();
};

class PostgresConnector : public Connector
{
public:
    PostgresConnector();
    std::vector<std::string> extract();
};

class RestApiConnector : public Connector
{
public:
    RestApiConnector();
    std::vector<std::string> extract();
};

class CsvConnector : public Connector
{
public:
    CsvConnector();
    std::vector<std::string> extract();
};

#endif