/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/
#include "Transformation.h"

Transformation::Transformation(std::string name)
{
    this->name = name;
}

std::string Transformation::getName()
{
    return name;
}

Transformation::~Transformation()
{
}