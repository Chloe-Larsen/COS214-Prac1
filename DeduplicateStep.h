/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef DEDUPLICATESTEP_H
#define DEDUPLICATESTEP_H

#include "Transformation.h"

class DeduplicateStep : public Transformation
{
public:
    DeduplicateStep();
    Transformation *clone() override;
    std::vector<std::string> apply(std::vector<std::string>) override;
};

#endif