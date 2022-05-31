/*
MIT License

Copyright (c) 2022 Piotr Nycz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "IsEqual.hpp"
#include "Spaceship.hpp"

#define APPLY_ARG1 a1
#define APPLY_ARG2 APPLY_ARG1,a2
#define APPLY_ARG3 APPLY_ARG2,a3
#define APPLY_ARG4 APPLY_ARG3,a4
#define APPLY_ARG5 APPLY_ARG4,a5
#define APPLY_ARG6 APPLY_ARG5,a6
#define APPLY_ARG7 APPLY_ARG6,a7
#define APPLY_ARG8 APPLY_ARG7,a8
#define APPLY_ARG9 APPLY_ARG8,a9
#define APPLY_ARG10 APPLY_ARG9,a10

#define DEFINE_APPLY_N(N) \
template <typename F, typename T> \
constexpr auto apply##N(const F& f, const T& object) { \
    auto& [APPLY_ARG##N] = object; \
    return f(APPLY_ARG##N); \
}
#define DEFINE_EQUAL_N(N) \
template <typename T> \
constexpr bool equal##N(const T& lhs, const T& rhs) { \
    return apply##N(apply##N(isEqual, lhs), rhs); \
}
#define DEFINE_SPACESHIP_N(N) \
template <typename T> \
constexpr int spaceship##N(const T& lhs, const T& rhs) { \
    return apply##N(apply##N(spaceship, lhs), rhs); \
}

#define DEFINE_COMPARE(N) \
  DEFINE_APPLY_N(N) \
  DEFINE_EQUAL_N(N) \
  DEFINE_SPACESHIP_N(N) \

DEFINE_COMPARE(1)
DEFINE_COMPARE(2)
DEFINE_COMPARE(3)
DEFINE_COMPARE(4)
DEFINE_COMPARE(5)
DEFINE_COMPARE(6)
DEFINE_COMPARE(7)
DEFINE_COMPARE(8)
DEFINE_COMPARE(9)
DEFINE_COMPARE(10)

#define DEFINE_COMPARE_FOR_CLASS(C,N) \
constexpr bool operator==(const C& lhs, const C& rhs) noexcept { return equal##N(lhs, rhs); } \
constexpr bool operator!=(const C& lhs, const C& rhs) noexcept { return !(lhs==rhs); } \
constexpr bool operator<(const C& lhs, const C& rhs) noexcept { return spaceship##N(lhs, rhs) < 0; } \
constexpr bool operator<=(const C& lhs, const C& rhs) noexcept { return spaceship##N(lhs, rhs) <= 0; } \
constexpr bool operator>(const C& lhs, const C& rhs) noexcept { return spaceship##N(lhs, rhs) > 0; } \
constexpr bool operator>=(const C& lhs, const C& rhs) noexcept { return spaceship##N(lhs, rhs) >= 0; }
