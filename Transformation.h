/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "Transformation.h"

class Transformation
{
protected:
    std::string name;

public:
    Transformation(std::string);
    virtual Transformation *clone() = 0;
    virtual std::vector<std::string> apply(std::vector<std::string>) = 0;
    std::string getName();
    virtual ~Transformation();
};

#endif