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

#define EQUAL_FIELD_1(a1) if (!(lhs.a1 == rhs.a1)) return false;
#define EQUAL_FIELD_2(a1, a2) EQUAL_FIELD_1(a1) EQUAL_FIELD_1(a2)
#define EQUAL_FIELD_3(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_2(__VA_ARGS__)
#define EQUAL_FIELD_4(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_3(__VA_ARGS__)
#define EQUAL_FIELD_5(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_4(__VA_ARGS__)
#define EQUAL_FIELD_6(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_5(__VA_ARGS__)
#define EQUAL_FIELD_7(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_6(__VA_ARGS__)
#define EQUAL_FIELD_8(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_7(__VA_ARGS__)
#define EQUAL_FIELD_9(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_8(__VA_ARGS__)
#define EQUAL_FIELD_10(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_9(__VA_ARGS__)
#define EQUAL_FIELD_11(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_10(__VA_ARGS__)
#define EQUAL_FIELD_12(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_11(__VA_ARGS__)
#define EQUAL_FIELD_13(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_12(__VA_ARGS__)
#define EQUAL_FIELD_14(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_13(__VA_ARGS__)
#define EQUAL_FIELD_15(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_14(__VA_ARGS__)
#define EQUAL_FIELD_16(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_15(__VA_ARGS__)
#define EQUAL_FIELD_17(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_16(__VA_ARGS__)
#define EQUAL_FIELD_18(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_17(__VA_ARGS__)
#define EQUAL_FIELD_19(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_18(__VA_ARGS__)
#define EQUAL_FIELD_20(a1, ...) EQUAL_FIELD_1(a1) EQUAL_FIELD_19(__VA_ARGS__)


#define LESS_FIELD_1(a1) if (lhs.a1 < rhs.a1) return true; \
                         if (rhs.a1 < lhs.a1) return false;
#define LESS_FIELD_2(a1, a2) LESS_FIELD_1(a1) LESS_FIELD_1(a2)
#define LESS_FIELD_3(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_2(__VA_ARGS__)
#define LESS_FIELD_4(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_3(__VA_ARGS__)
#define LESS_FIELD_5(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_4(__VA_ARGS__)
#define LESS_FIELD_6(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_5(__VA_ARGS__)
#define LESS_FIELD_7(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_6(__VA_ARGS__)
#define LESS_FIELD_8(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_7(__VA_ARGS__)
#define LESS_FIELD_9(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_8(__VA_ARGS__)
#define LESS_FIELD_10(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_9(__VA_ARGS__)
#define LESS_FIELD_11(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_10(__VA_ARGS__)
#define LESS_FIELD_12(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_11(__VA_ARGS__)
#define LESS_FIELD_13(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_12(__VA_ARGS__)
#define LESS_FIELD_14(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_13(__VA_ARGS__)
#define LESS_FIELD_15(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_14(__VA_ARGS__)
#define LESS_FIELD_16(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_15(__VA_ARGS__)
#define LESS_FIELD_17(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_16(__VA_ARGS__)
#define LESS_FIELD_18(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_17(__VA_ARGS__)
#define LESS_FIELD_19(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_18(__VA_ARGS__)
#define LESS_FIELD_20(a1, ...) LESS_FIELD_1(a1) LESS_FIELD_19(__VA_ARGS__)
