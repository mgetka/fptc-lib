Fixed Point Math Library for C
===============================

This repository contains a fork of [Fixed Point Math Library for C](https://sourceforge.net/projects/fixedptc/) improved with some additional functionalities.

[![Build Status](https://travis-ci.com/mgetka/fptc-lib.svg?branch=master)](https://travis-ci.com/mgetka/fptc-lib)

Features of original library:

 * Fixed point math library
 * Requires a fairly modern C compiler with `uint32_t` and `uint64_t`
 * 32-bit and 64-bit precision support (for compilers with `__int128_t` extensions like `gcc`)
 * Arbitrary precision point (e.g. 24.8 or 32.32)
 * Pure header-only
 * Pure integer-only (suitable for kernels, embedded CPUs, etc)

This version features also

 * Floating point free conversion from strings to `fpt` values
 * Conversion from `fpt` to string returns string size
 * Normalized conversion between `fpt` and `int`
 * Over/underflow detection and handling
 * And other minor improvements...

### Normalization

Once the decimal point position is chosen, it is set for the whole project. Normalization is useful,
when some of the variables are of the different order of magnitude than others. The idea here is to
scale the variables so they are represented by a variable with approximately unary order of
magnitude, and then, when the calculations are finished, to scale back to original form.

![equation](https://latex.codecogs.com/svg.latex?%5Cbegin%7Balign*%7D%20A%5E*%20%26%20%5Cleftarrow%20A%20%5Calpha%20%26%20%5Cquad%20%26%20%5Ctextrm%7Bnormalize%20variables%7D%20%5C%5C%20B%5E*%20%26%20%5Cleftarrow%20f%28A%5E*%29%20%26%20%5Cquad%20%26%20%5Ctextrm%7Bperform%20your%20numerical%20magic%7D%20%5C%5C%20B%20%26%20%5Cleftarrow%20B%5E*%20%5Calpha%5E%7B-1%7D%20%26%20%5Cquad%20%26%20%5Ctextrm%7Bdenormalize%20results%7D%20%5Cend%7Balign*%7D)

It is the developer duty to keep track of which variable has which normalization factor applied.
Usefulness of such approach was proven for cases such as discrete adaptive control system
implementation or solving of a linear equation systems via matrix decomposition. 

### License

This modified library is released under the same license as the original one, ie. [BSD-2](LICENSE).
`LICENSE` file features original authors copyrights disclosures.