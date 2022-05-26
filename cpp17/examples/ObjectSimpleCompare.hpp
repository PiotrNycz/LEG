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

#include "ObjectSimple.hpp"
#include "ColorSimpleCompare.hpp"

constexpr bool operator==(const Object& lhs, const Object& rhs) noexcept
{
    return lhs.x == rhs.x
        && lhs.y == rhs.y
        && lhs.hasZ == rhs.hasZ
        && (!lhs.hasZ || (lhs.z == rhs.z))
        && lhs.weight == rhs.weight
        && lhs.velocity == rhs.velocity
        && lhs.color == rhs.color;
}

constexpr bool operator<(const Object& lhs, const Object& rhs) noexcept
{
    if (lhs.x < rhs.x) return true;
    if (rhs.x < lhs.x) return false;

    if (lhs.y < rhs.y) return true;
    if (rhs.y < lhs.y) return false;

    if (lhs.hasZ != rhs.hasZ) return rhs.hasZ;

    if (lhs.hasZ)
    {
        if (lhs.z < rhs.z) return true;
        if (rhs.z < lhs.z) return false;
    }

    if (lhs.weight < rhs.weight) return true;
    if (rhs.weight < lhs.weight) return false;

    if (lhs.velocity < rhs.velocity) return true;
    if (rhs.velocity < lhs.velocity) return false;

    return lhs.color < rhs.color;
}

constexpr bool operator!=(const Object& lhs, const Object& rhs) noexcept
{
    return !(lhs == rhs);
}
constexpr bool operator>(const Object& lhs, const Object& rhs) noexcept
{
    return rhs < lhs;
}
constexpr bool operator<=(const Object& lhs, const Object& rhs) noexcept
{
    return !(rhs < lhs);
}
constexpr bool operator>=(const Object& lhs, const Object& rhs) noexcept
{
    return !(lhs < rhs);
}
