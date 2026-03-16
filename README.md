# Pi Formulae
Just some interesting formulae for approximating pi, with graphs. Made for Pi Day 2026.

## Formulae
#### Madhava-Leibniz formula
Dervied from the Taylor series expansion of $arctan(1)$

$\pi=4\sum_{n=1}^\infty \frac{(-1)^n}{2n+1}$

#### Nilakantha series
Refinement to the Madhava-Leibniz formula.

$\pi=3+4\sum_{n=1}^\infty \frac{(-1)^{n+1}}{(2n)(2n+1)(2n+2)}$

#### Ramanujan formula
I don't know how this works. This one is just magic, I think.

$\frac{1}{\pi}=\frac{2\sqrt{2}}{9801}\sum_{n=0}^\infty \frac{(4n)!(1103+26390n)}{396^{4n}(n!)^4}$

## Building
The project can be built using CMake. All dependencies are included as Git submodules (use a recursive clone to get these).

```
mkdir build
cd build
cmake ..
```