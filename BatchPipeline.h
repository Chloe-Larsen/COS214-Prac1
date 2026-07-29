#ifndef BATCHPIPELINE_H
#define BATCHPIPELINE_H

#include "Pipeline.h"

class BatchPipeline : public Pipeline
{
protected:
    void extract();
    void load();
};

#endif