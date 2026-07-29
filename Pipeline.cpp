#include "Pipeline.h"

void Pipeline::connect()
{
}

void Pipeline::extract()
{
}

void Pipeline::transform()
{
}

void Pipeline::load()
{
}

Pipeline::Pipeline(ConnectorFactory *)
{
}

void Pipeline::run()
{
}

void Pipeline::addStep(Transformation *)
{
}

RunCheckpoint *Pipeline::createCheckpoint()
{
}

void Pipeline::restore(RunCheckpoint *)
{
}

Pipeline::~Pipeline()
{
}