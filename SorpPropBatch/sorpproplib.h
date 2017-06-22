#ifndef SORPPROPLIB_H
#define SORPPROPLIB_H

#include "sorpproplib_global.h"

#include <iostream>

class SORPPROPLIBSHARED_EXPORT SorpPropLib
{

public:
    SorpPropLib();

    void calc(std::string ref, std::string sorb, double tK, double xMass);
};

#endif // SORPPROPLIB_H
