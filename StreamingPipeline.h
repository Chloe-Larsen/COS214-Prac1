/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef STREAMINGPIPELINE_H
#define STREAMINGPIPELINE_H

#include "Pipeline.h"
#include "Connector.h"

class StreamingPipeline : public Pipeline
{
protected:
    void extract();
    void load();
};

#endif