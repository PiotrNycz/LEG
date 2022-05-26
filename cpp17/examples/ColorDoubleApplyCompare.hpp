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

#include "Color.hpp"
#include "IsEqual.hpp"
#include "Spaceship.hpp"

template <typename F>
constexpr auto apply(const F& f, const Color& arg) noexcept
{
    return f(arg.r, arg.g, arg.b);
}

constexpr bool operator==(const Color& lhs, const Color& rhs) noexcept
{
    const auto lhs_equal_to = apply(isEqual, lhs);
    return apply(lhs_equal_to, rhs);
}
constexpr bool operator!=(const Color& lhs, const Color& rhs) noexcept
{
    return !(lhs == rhs);
}

constexpr int compare(const Color& lhs, const Color& rhs) noexcept
{
    const auto lhs_spaceship_to = apply(spaceship, lhs);
    return apply(lhs_spaceship_to, rhs);
}

constexpr bool operator<(const Color& lhs, const Color& rhs) noexcept
{
    return compare(lhs, rhs) < 0;
}

constexpr bool operator>(const Color& lhs, const Color& rhs) noexcept
{
    return compare(lhs, rhs) > 0;
}
constexpr bool operator<=(const Color& lhs, const Color& rhs) noexcept
{
    return compare(lhs, rhs) <= 0;
}

constexpr bool operator>=(const Color& lhs, const Color& rhs) noexcept
{
    return compare(lhs, rhs) >= 0;
}
