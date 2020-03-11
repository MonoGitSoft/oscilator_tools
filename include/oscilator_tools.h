#ifndef OSCILATOR_TOOLS_H
#define OSCILATOR_TOOLS_H

#include "common.h"

#include <iostream>

namespace oscilator {

struct OscilatorTools
{
    OscilatorTools() = delete;

    static void calcNorm(OscilatorSignal &signal, OscilatorNorm& norm);

    static void calcNormOnInterval(OscilatorSignal &signal, OscilatorNorm &norm, InterVal& interval)
    {
        for(int i = interval.m_First; i < interval.m_Last; ++i)
        {
            norm.getNorm(i) = std::sqrt(std::pow(signal.getX(i), 2) + std::pow(signal.getY(i), 2) + std::pow(signal.getZ(i), 2));
        }
    }
};

}


#endif // OSCILATOR_TOOLS_H
