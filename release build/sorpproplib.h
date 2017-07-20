#ifndef SORPPROPLIB_H
#define SORPPROPLIB_H

#include "sorpproplib_global.h"

#include <iostream>
#include <map>

class SORPPROPLIBSHARED_EXPORT SorpPropLib
{

public:
    SorpPropLib();

    std::string calc(std::string ref, std::string sorb, double tK, double xMass);
};

#endif // SORPPROPLIB_H
