/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "BatchPipeline.h"

void BatchPipeline::extract()
{
    Connector *connector = factory->createConnector();
    records = connector->extract();
    std::cout << "Batch extract: " << records.size() << " records" << std::endl;
    stage = 2;
    delete connector;
}

void BatchPipeline::load()
{
    std::cout << "Batch load: " << records.size() << " records written" << std::endl;
    stage = 4;
}