#include "Connector.h"

Connector::Connector(std::string source) : source(source)
{
}

std::string Connector::getSource()
{
    return source;
}

Connector::~Connector()
{
}

PostgresConnector::PostgresConnector() : Connector("postgres")
{
}

std::vector<std::string> PostgresConnector::extract()
{
    std::vector<std::string> result;
    result.push_back("PG:001");
    result.push_back("PG:002");
    result.push_back("PG:002");
    result.push_back("PG:003");
    return result;
}

RestApiConnector::RestApiConnector() : Connector("restapi")
{
}

std::vector<std::string> RestApiConnector::extract()
{
    std::vector<std::string> result;
    result.push_back("API:44");
    result.push_back("API:45");
    result.push_back("API:45");    
    return result;
}

CsvConnector::CsvConnector() : Connector("csv")
{
}

std::vector<std::string> CsvConnector::extract()
{
    std::vector<std::string> result;
    result.push_back("CSV:x1");
    result.push_back("CSV:x2");
    result.push_back("CSV:x3");
    result.push_back("CSV:x3");
    return result;
}