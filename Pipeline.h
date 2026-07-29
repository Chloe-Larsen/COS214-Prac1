#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>g
#include <string>
#include <iostream>
#include <map>

#include "ConnectorFactory.h"
#include "Transformation.h"
#include "RunCheckpoint.h"

class Pipeline{
protected:
    ConnectorFactory* factory;
    std::vector<Transformation *> steps;
    int stage;
    std::vector<std::string> records;

    void connect();
    virtual void extract();
    void transform();
    virtual void load();

public:
    Pipeline(ConnectorFactory *);
    void run();
    void addStep(Transformation *);
    RunCheckpoint * createCheckpoint();
    void restore(RunCheckpoint*);
    ~Pipeline();
};

#endif