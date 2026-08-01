/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "CheckpointManager.h"

void CheckpointManager::save(RunCheckpoint *checkpoint)
{
    history.push_back(checkpoint);
}

RunCheckpoint *CheckpointManager::undo()
{
    if (history.empty())
        return nullptr;

    RunCheckpoint *checkpoint = history.back();
    history.pop_back();
    return checkpoint;
}

CheckpointManager::~CheckpointManager()
{
    for (RunCheckpoint *checkpoint : history)
    {
        delete checkpoint;
    }
}