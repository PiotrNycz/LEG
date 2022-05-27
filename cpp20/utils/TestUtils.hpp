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

#include <cassert>
#include <iterator>
#include <algorithm>
#include <compare>

template <typename T>
void assertEqual(const T& lhs, const T& rhs)
{
    assert(lhs == rhs);
    assert((lhs<=>rhs) == 0);
}

template <typename T>
void assertLess(const T& lhs, const T& rhs)
{
    assert(!(lhs == rhs));
    assert((lhs<=>rhs) < 0);
}

template <typename Range>
void assertAscendingOrder(const Range& sortedList)
{
    using std::begin;
    using std::end;
    auto lhs = begin(sortedList);
    const auto endRange = end(sortedList);
    for (; lhs != endRange; ++lhs)
    {
        assertEqual(*lhs, *lhs);
        for (auto rhs = std::next(lhs); rhs != endRange; ++rhs)
            assertLess(*lhs, *rhs);
    }
}