/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "StreamingPipeline.h"

void StreamingPipeline::extract()
{
    Connector *connector = factory->createConnector();
    records = connector->extract();
    std::cout << "Streaming extract: " << records.size() << " records" << std::endl;
    stage = 2;
    delete connector;
}

void StreamingPipeline::load()
{
    std::cout << "Streaming load: " << records.size() << " records streamed" << std::endl;
    stage = 4;
}