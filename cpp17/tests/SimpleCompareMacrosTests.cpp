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

#include "SimpleCompareMacros.hpp"
#include <cassert>

namespace {
const int f1=1, f2=2, f3=3, f4=4, f5=5, f6=6, f7=7, f8=8, f9=9, f10=10,
   f11=11, f12=12, f13=13, f14=14, f15=15, f16=16, f17=17, f18=18, f19=19, f20=20;
struct ForTest {
    int f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
       f11,f12,f13,f14,f15,f16,f17,f18,f19, f20;
};
}
#define FOR_TEST_CODE_N(N, ...) \
auto ForTestEqual##N = [](const auto& lhs, const auto& rhs) { \
    EQUAL_FIELD_##N(__VA_ARGS__) \
    return true; \
}; \
auto ForTestLess##N = [](const auto& lhs, const auto& rhs) { \
    LESS_FIELD_##N(__VA_ARGS__) \
    return false; \
}

#define FOR_TEST_N(N, ...) FOR_TEST_CODE_N(N, __VA_ARGS__); \
auto DoTest##N = [] { \
    int f1 = 1; \
    int f##N = N; \
    ForTest forTest1{__VA_ARGS__}; \
    f##N = N + 100; \
    ForTest forTest2{__VA_ARGS__}; \
    f1 = 101; \
    ForTest forTest3{__VA_ARGS__}; \
    assert(ForTestEqual##N(forTest1, forTest1)); \
    assert(!ForTestEqual##N(forTest1, forTest2)); \
    assert(!ForTestEqual##N(forTest1, forTest3)); \
    assert(ForTestLess##N(forTest1, forTest2)); \
    assert(ForTestLess##N(forTest1, forTest3)); \
    assert(ForTestLess##N(forTest2, forTest3)); \
    assert(!ForTestLess##N(forTest1, forTest1)); \
    assert(!ForTestLess##N(forTest2, forTest1)); \
    assert(!ForTestLess##N(forTest3, forTest1)); \
    assert(!ForTestLess##N(forTest3, forTest2)); \
}

FOR_TEST_CODE_N(1, f1);
FOR_TEST_N(2, f1, f2);
FOR_TEST_N(3, f1, f2, f3);
FOR_TEST_N(4, f1, f2, f3, f4);
FOR_TEST_N(5, f1, f2, f3, f4, f5);
FOR_TEST_N(6, f1, f2, f3, f4, f5, f6);
FOR_TEST_N(7, f1, f2, f3, f4, f5, f6, f7);
FOR_TEST_N(8, f1, f2, f3, f4, f5, f6, f7, f8);
FOR_TEST_N(9, f1, f2, f3, f4, f5, f6, f7, f8, f9);
FOR_TEST_N(10, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10);
FOR_TEST_N(11, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11);
FOR_TEST_N(12, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12);
FOR_TEST_N(13, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13);
FOR_TEST_N(14, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13, f14);
FOR_TEST_N(15, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13, f14, f15);
FOR_TEST_N(16, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13, f14, f15, f16);
FOR_TEST_N(17, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13, f14, f15, f16, f17);
FOR_TEST_N(18, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13, f14, f15, f16, f17, f18);
FOR_TEST_N(19, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13, f14, f15, f16, f17, f18, f19);
FOR_TEST_N(20, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10,
    f11, f12, f13, f14, f15, f16, f17, f18, f19, f20);

int main() {
    assert(ForTestEqual1(ForTest{1}, ForTest{1}));
    assert(!ForTestEqual1(ForTest{1}, ForTest{2}));
    assert(ForTestLess1(ForTest{1}, ForTest{2}));
    assert(!ForTestLess1(ForTest{1}, ForTest{1}));
    assert(!ForTestLess1(ForTest{2}, ForTest{1}));

    DoTest2();
    DoTest3();
    DoTest4();
    DoTest5();
    DoTest6();
    DoTest7();
    DoTest8();
    DoTest9();
    DoTest10();
    DoTest11();
    DoTest12();
    DoTest13();
    DoTest14();
    DoTest15();
    DoTest16();
    DoTest17();
    DoTest18();
    DoTest19();
    DoTest20();
}
