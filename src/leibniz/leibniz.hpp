#pragma once

#include <vector>

namespace leibniz {
    inline static int n = 0;
    inline static double total = 0.0;

    inline bool running = false;
    inline std::vector<float> values;

    double next();

    void reset();
}