#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "RunCheckpoint.h"

class CheckpointManager
{
private:    
    std::vector<RunCheckpoint*> history;
public:
    void save(RunCheckpoint*);
    RunCheckpoint* undo();
    ~CheckpointManager();
};

#endif