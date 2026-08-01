/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef BATCHPIPELINE_H
#define BATCHPIPELINE_H

#include "Pipeline.h"
#include "Connector.h"

class BatchPipeline : public Pipeline
{
protected:
    void extract();
    void load();
};

#endif