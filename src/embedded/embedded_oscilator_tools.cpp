#include "oscilator_tools.h"

using namespace oscilator;

void OscilatorTools::calcNorm(OscilatorSignal &signal, OscilatorNorm &norm)
{
    oscilator::InterVal all(0, norm.size());
    oscilator::OscilatorTools::calcNormOnInterval(signal, norm, all);
}


