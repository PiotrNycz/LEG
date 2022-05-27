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

#include "TestUtils.hpp"
#include "Object.hpp"

inline void testObjectCompare()
{
    Object sortedList[] {
        // color ------------------------+
        // velocity -----------------+   |
        // weight ----------------+  |   |
        // z-------------+----+   |  |   |-----+
        // y ------+     |    |   |  |   |--+  |
        // x ---v  v     v    v   v  v   v  v  v
        Object{ 1, 2, {false, 0}, 4, 5, {6, 7, 8}},
        Object{ 1, 2, {false, 0}, 4, 5, {6, 7, 9}},
        Object{ 1, 2, {false, 0}, 4, 9, {6, 7, 8}},
        Object{ 1, 2, {false, 0}, 9, 5, {6, 7, 8}},
        Object{ 1, 2, {true,  9}, 4, 5, {6, 7, 8}},
        Object{ 1, 9, {false, 0}, 4, 5, {6, 7, 8}},
        Object{ 9, 2, {false, 0}, 4, 5, {6, 7, 8}},
    };
    assertEqual(Object{ 1, 2, {false, 0}, 4, 5, {6, 7, 8}},
                Object{ 1, 2, {false, 9}, 4, 5, {6, 7, 8}});
    assertLess( Object{ 1, 2, {false, 9}, 4, 5, {6, 7, 8}},
                Object{ 1, 2, {true,  3}, 4, 5, {6, 7, 8}});
}
