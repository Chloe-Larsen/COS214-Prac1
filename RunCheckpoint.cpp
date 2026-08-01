/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "RunCheckpoint.h"

RunCheckpoint::RunCheckpoint(int stage, std::vector<std::string> records)
{
    this->stage = stage;
    this->records = records;
}

int RunCheckpoint::getStage()
{
    return stage;
}

std::vector<std::string> RunCheckpoint::getRecords()
{
    return records;
}