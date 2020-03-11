#include <iostream>
#include <chrono>

#include "common.h"
#include "oscilator_tools.h"
using namespace std;



int main()
{
    oscilator::OscilatorSignal signal;
    oscilator::OscilatorNorm norm;
    double a_x(10);
    double a_y(20);
    double a_z(40);

    double w_x(10);
    double w_y(20);
    double w_z(40);

    for(int i = 0; i < signal.size(); i++)
    {
        signal.getX(i) = a_x*sin(w_x * i * oscilator::SAMPLE_TIME);
        signal.getY(i) = a_y*sin(w_y * i * oscilator::SAMPLE_TIME);
        signal.getZ(i) = a_z*sin(w_z * i * oscilator::SAMPLE_TIME);
    }


    auto start = std::chrono::system_clock::now();

    oscilator::OscilatorTools::calcNorm(signal, norm);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Threaded exec time: " << diff.count() << std::endl;

    oscilator::InterVal all(0, norm.size());

    start = std::chrono::system_clock::now();
    // do some work
    oscilator::OscilatorTools::calcNormOnInterval(signal, norm, all);
    end = std::chrono::system_clock::now();
    diff = end-start;
    std::cout << "One thread exec time: " << diff.count() << std::endl;

    return 0;
}
