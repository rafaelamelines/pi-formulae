#include "leibniz.hpp"

double leibniz::next() {
    int x = n % 2 == 0 ? 1 : -1;
    int y = 2 * n + 1;

    total += (double)x / (double)y;

    n++;

    return 4 * total;
}

void leibniz::reset() {
    n = 0;
    total = 0.0;
    values.clear();
}