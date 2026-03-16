#include "nilakantha.hpp"

double nilakantha::next() {
    int x = n % 2 == 0 ? -1 : 1;
    int y = (2 * n) * (2 * n + 1) * (2 * n + 2);

    total += (double)x / (double)y;

    n++;

    return 3 + 4 * total;
}

void nilakantha::reset() {
    n = 1;
    total = 0.0;
    values.clear();
}