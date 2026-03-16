#pragma once

#include <vector>

namespace nilakantha {
    inline static int n = 1;
    inline static double total = 0.0;

    inline bool running = false;
    inline std::vector<float> values;

    double next();

    void reset();
}