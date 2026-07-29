#ifndef STREAMINGPIPELINE_H
#define STREAMINGPIPELINE_H

#include "Pipeline.h"

class StreamingPipeline : public Pipeline
{
protected:
    void extract();
    void load();
};

#endif