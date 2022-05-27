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

#include <unordered_map>
#include <compare>
#include "IgnoreWhenCompare.hpp"

class Quadratic {
public:
    Quadratic(double a, double b, double c)
        : a(a), b(b), c(c)
    {}
    bool operator==(const Quadratic& rhs) const = default;
    auto operator<=>(const Quadratic& rhs) const = default;

    double operator()(double x) const {
        if (auto it = cachedResults.value.find(x); it != cachedResults.value.end())
            return it->second;
        return cachedResults.value.emplace(x, a*x*x + b*x + c).first->second;
    }

private:
    // a*x*x + b*x + c
    double a, b, c;
    using CachedResults = std::unordered_map<double, double>;
    mutable IgnoreWhenCompare<CachedResults> cachedResults;
};
