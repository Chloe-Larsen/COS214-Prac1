/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "AggregateByRegionStep.h"

AggregateByRegionStep::AggregateByRegionStep() : Transformation("aggregate") {}

Transformation *AggregateByRegionStep::clone()
{
    return new AggregateByRegionStep();
}

std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> input)
{
    std::vector<std::string> output;
    output.push_back("COUNT=" + input.size());
    return output;
}