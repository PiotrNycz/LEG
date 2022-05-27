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

#include "CompareMacros.hpp"
#include <cassert>

struct ForTest {
    int f1, f2;
    bool operator==(const ForTest& rhs) const
    {
        const auto& lhs = *this;
        EQUAL_FIELDS((f1)(f2))
    }
    inline bool operator<(const ForTest& rhs) const
    {
        const auto& lhs = *this;
        LESS_FIELDS((f1)(f2))
    }
};

int main() {
    assert((ForTest{1, 2} == ForTest{1, 2}));
    assert(!(ForTest{1, 3} == ForTest{1, 2}));
    assert(!(ForTest{2, 1} == ForTest{1, 2}));
    assert(!(ForTest{0, 0} == ForTest{1, 2}));

    assert(!(ForTest{1, 2} < ForTest{1, 2}));
    assert(!(ForTest{1, 3} < ForTest{1, 2}));
    assert(!(ForTest{2, 1} < ForTest{1, 2}));
    assert((ForTest{0, 0} < ForTest{1, 2}));
}
