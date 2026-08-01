/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "ConnectorFactory.h"
#include "Transformation.h"
#include "RunCheckpoint.h"

class Pipeline
{
protected:
    ConnectorFactory *factory;
    std::vector<Transformation *> steps;
    int stage;
    std::vector<std::string> records;

    void connect();
    virtual void extract() = 0;
    void transform();
    virtual void load() = 0;

public:
    Pipeline(ConnectorFactory *);
    void run();
    void addStep(Transformation *);
    RunCheckpoint *createCheckpoint();
    void restore(RunCheckpoint *);
    ~Pipeline();
};

#endif