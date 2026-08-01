/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include <iostream>
#include "DeduplicateStep.h"

DeduplicateStep::DeduplicateStep() : Transformation("dedup") {}

Transformation *DeduplicateStep::clone()
{
    return new DeduplicateStep();
}

std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> input)
{
    bool set = false;
    std::string current;
    std::vector<std::string> output;

    for (std::string &v : input)
    {
        if (set && v == current)
            continue;

        current = v;
        set = true;
        output.push_back(v);
    }

    return output;
}