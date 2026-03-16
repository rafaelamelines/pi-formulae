#pragma once

#include <vector>

namespace ramanujan {
    inline static int n = 0;
    inline static double total = 0.0;

    inline std::vector<float> values;

    double next();

    void reset();
}