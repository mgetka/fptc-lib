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

 * Floating point free conversion from strings to fpt values,
 * Conversion from fpt to string returns string size,
 * Normalized conversion between fpt and int,
 * Over/underflow detection and handling,
 * And other minor improvements...
