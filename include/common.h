#ifndef COMMON_H
#define COMMON_H

#include <math.h>

namespace oscilator {

    const double SIGNAL_INTERVAL = 20 * M_PI;
    const double SAMPLE_TIME = 10e-4;
    const size_t SAMPLE_NUM = SIGNAL_INTERVAL / SAMPLE_TIME;

    class OscilatorSignal
    {
    public:
        OscilatorSignal(): m_Zero(0)
        {
        }

        double& getX(size_t n)
        {
            if(n >= SAMPLE_NUM)
            {
                return m_Zero;
            }
            return m_SignalX[n];
        }

        double& getY(size_t n)
        {
            if(n >= SAMPLE_NUM)
            {
                return m_Zero;
            }
            return m_SignalY[n];
        }

        double& getZ(size_t n)
        {
            if(n >= SAMPLE_NUM)
            {
                return m_Zero;
            }
            return m_SignalZ[n];
        }

        size_t size()
        {
            return SAMPLE_NUM;
        }

    private:
        double m_SignalX[SAMPLE_NUM] = {0};
        double m_SignalY[SAMPLE_NUM] = {0};
        double m_SignalZ[SAMPLE_NUM] = {0};

        double m_Zero;
    };

    class OscilatorNorm
    {
    public:

        OscilatorNorm(): m_Zero(0.0)
        {
        }

        double& getNorm(size_t n)
        {
            if(n > SAMPLE_NUM)
            {
                return m_Zero;
            }
            return m_SignalNorm[n];
        }

        size_t size()
        {
            return SAMPLE_NUM;
        }

    private:
        double m_SignalNorm[SAMPLE_NUM] = {0};
        double m_Zero;
    };

    struct InterVal
    {
        InterVal() = default;

        InterVal(size_t first, size_t last) : m_First(first), m_Last(last)
        {
        }

        size_t m_First;
        size_t m_Last;
    };
}

#endif // COMMON_H
