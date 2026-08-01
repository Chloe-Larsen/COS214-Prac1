#ifndef TRANSFORMATIONREGISTRY_H
#define TRANSFORMATIONREGISTRY_H

/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "Transformation.h"

class TransformationRegistry
{
private:
    std::map<std::string, Transformation> prototypes;

public:
    void registerStep(std::string, Transformation *);
    Transformation* create(std::string);
    ~TransformationRegistry();
};

#endif