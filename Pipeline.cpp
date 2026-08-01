/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "Pipeline.h"

void Pipeline::connect()
{
    Connector *connector = factory->createConnector();
    std::cout << "Connecting to " << connector->getSource() << std::endl;
    stage = 1;
    delete connector;
}

void Pipeline::transform()
{
    for (auto step : steps)
    {
        records = step->apply(records);
    }
    stage = 3;
}

Pipeline::Pipeline(ConnectorFactory *factory) : factory(factory), stage(0), records()
{
}

void Pipeline::run()
{
    connect();
    extract();
    transform();
    load();
}

void Pipeline::addStep(Transformation *step)
{
    steps.push_back(step);
}

RunCheckpoint *Pipeline::createCheckpoint() // Task 4 - Caleb
{
    return NULL;
}

void Pipeline::restore(RunCheckpoint *) // Task 4 - Caleb
{
}

Pipeline::~Pipeline()
{
    if (factory != nullptr)
        delete factory;

    for (auto step : steps)
    {
        delete step;
    }
}