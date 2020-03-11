#include "oscilator_tools.h"
#include <thread>
#include <math.h>
#include <memory>
#include <vector>
#include <utility>

using namespace oscilator;



void OscilatorTools::calcNorm(OscilatorSignal &signal, OscilatorNorm &norm)
{
    size_t numOfThread = 8;
    size_t sampleSize = signal.size();
    size_t interval = sampleSize / numOfThread;

    size_t startFirst = 0;

    InterVal interVals[numOfThread];
    for(int i = 0; i < numOfThread; ++i)
    {
        interVals[i] = InterVal(startFirst, startFirst + interval);
        startFirst += interval;
    }
    interVals[numOfThread-1].m_Last = signal.size();

    std::vector<std::thread> threads;

    for(auto& interval : interVals)
    {
        threads.emplace_back(calcNormOnInterval, std::ref(signal), std::ref(norm), std::ref(interval));
    }

    for(auto& th : threads)
    {
        if(th.joinable())
        {
            th.join();
        }
    }
}


