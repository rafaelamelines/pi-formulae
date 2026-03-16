#include "ramanujan.hpp"

#include <cmath>

double ramanujan::next() {
    long long x = 1;

    for (int i = 2; i < 4 * n; i++) {
        x *= i;
    }

    long long y = 1103 + 26390 * n;

    long long z = 1;

    for (int i = 2; i < n; i++) {
        z *= i;
    }

    long long a = z * z * z * z * std::pow(396, 4 * n);

    total += (double)((long double)x * (long double)y / (long double)a);

    n++;

    return 9801.0 / total / 2.0 / std::sqrt(2.0);
}

void ramanujan::reset() {
    n = 0;
    total = 0.0;
    values.clear();
}