/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "TransformationRegistry.h"

#include <iostream>
#include <map>
#include <string>

void TransformationRegistry::registerStep(std::string key, Transformation *transformation)
{
    std::map<std::string, Transformation *>::iterator it = prototypes.find(key);

    if (it == prototypes.end())
    {
        // does not contain key
        prototypes[key] = transformation;
    }
    else
    {
        // contains

        if (it->second == transformation)
            return; // don't change anything

        delete it->second;           // delete transformation
        it->second = transformation; // replace with new transformation
    }
}

Transformation *TransformationRegistry::create(std::string key)
{
    std::map<std::string, Transformation *>::iterator it = prototypes.find(key);
    return (it == prototypes.end()) ? nullptr : it->second->clone();
}

TransformationRegistry::~TransformationRegistry()
{
    for (std::map<std::string, Transformation *>::iterator it = prototypes.begin(); it != prototypes.end(); ++it)
    {
        delete it->second;
    }
}