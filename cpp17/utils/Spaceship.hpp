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

namespace details
{
template <typename V>
constexpr static int spaceship(const V& lhs, const V& rhs) noexcept
{
    if (lhs < rhs) return -1;
    if (rhs < lhs) return 1;
    return 0;
}
template <typename ...V>
constexpr static int spaceship(const V& ...lhs, const V& ...rhs) noexcept
{
    int result = 0;
    static_cast<void>(
        ((0 == (result = spaceship(lhs, rhs))) && ...)
    );
    return result;
}

}

struct Spaceship {
    template <typename ...V>
    constexpr auto operator()(const V& ...lhs) const noexcept 
    {
        return [&lhs...](const V& ...rhs) {
            return details::spaceship<V...>(lhs..., rhs...);
        };
    }
};
constexpr Spaceship spaceship{};

/// store lhs by value, thus allowing to use extra wrappers for values
struct SpaceshipByValue {
    template <typename ...V>
    constexpr auto operator()(const V& ...lhs) const noexcept 
    {
        return [lhs...](const V& ...rhs) {
            return details::spaceship<V...>(lhs..., rhs...);
        };
    }
};
constexpr SpaceshipByValue spaceshipByValue{};
