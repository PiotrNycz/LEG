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

#include "DoubleApplyMacros.hpp"
#include "TestUtils.hpp"
#include <cassert>
#include <cstdint>

namespace
{
struct ForTest1 {
    int f1;
};
struct ForTest2 {
    int f1, f2;
};
struct ForTest3 {
    int f1, f2, f3;
};
struct ForTest4 {
    int f1, f2, f3, f4;
};
struct ForTest5 {
    int f1, f2, f3, f4, f5;
};
struct ForTest6 {
    int f1, f2, f3, f4, f5, f6;
};
struct ForTest7 {
    int f1, f2, f3, f4, f5, f6, f7;
};
struct ForTest8 {
    int f1, f2, f3, f4, f5, f6, f7, f8;
};
struct ForTest9 {
    int f1, f2, f3, f4, f5, f6, f7, f8, f9;
};
struct ForTest10 {
    int f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;
};

DEFINE_COMPARE_FOR_CLASS(ForTest1, 1)
DEFINE_COMPARE_FOR_CLASS(ForTest2, 2)
DEFINE_COMPARE_FOR_CLASS(ForTest3, 3)
DEFINE_COMPARE_FOR_CLASS(ForTest4, 4)
DEFINE_COMPARE_FOR_CLASS(ForTest5, 5)
DEFINE_COMPARE_FOR_CLASS(ForTest6, 6)
DEFINE_COMPARE_FOR_CLASS(ForTest7, 7)
DEFINE_COMPARE_FOR_CLASS(ForTest8, 8)
DEFINE_COMPARE_FOR_CLASS(ForTest9, 9)
DEFINE_COMPARE_FOR_CLASS(ForTest10, 10)

}

int main() {
    ForTest1 forTest1[]{{1},{2}};
    assertAscendingOrder(forTest1);
    ForTest2 forTest2[]{{1,2},{1,3},{2,1},{2,9}};
    assertAscendingOrder(forTest2);
    ForTest3 forTest3[]{{1,2,3},{1,2,4},{2,1,1},{2,3,4}};
    assertAscendingOrder(forTest3);
    ForTest4 forTest4[]{{1,2,3,4},{1,2,3,5},{2,1,1,1},{2,3,4,5}};
    assertAscendingOrder(forTest4);
    ForTest5 forTest5[]{
        {1,2,3,4,5},
        {1,2,3,4,6},
        {2,1,1,1,1},
        {2,3,4,5,6}};
    assertAscendingOrder(forTest5);
    ForTest6 forTest6[]{
        {1,2,3,4,5,6},
        {1,2,3,4,5,7},
        {2,1,1,1,1,1},
        {2,3,4,5,6,7}};
    assertAscendingOrder(forTest6);
    ForTest7 forTest7[]{
        {1,2,3,4,5,6,7},
        {1,2,3,4,5,6,8},
        {2,1,1,1,1,1,1},
        {2,3,4,5,6,7,8}};
    assertAscendingOrder(forTest7);
    ForTest8 forTest8[]{
        {1,2,3,4,5,6,7,8},
        {1,2,3,4,5,6,7,9},
        {2,1,1,1,1,1,1,1},
        {2,3,4,5,6,7,8,9}};
    assertAscendingOrder(forTest8);
    ForTest9 forTest9[]{
        {1,2,3,4,5,6,7,8,9},
        {1,2,3,4,5,6,7,8,10},
        {2,1,1,1,1,1,1,1,1},
        {2,3,4,5,6,7,8,9,10}};
    assertAscendingOrder(forTest9);
    ForTest10 forTest10[]{
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,11},
        {2,1,1,1,1,1,1,1,1,1},
        {2,3,4,5,6,7,8,9,10,11}};
    assertAscendingOrder(forTest10);
}
