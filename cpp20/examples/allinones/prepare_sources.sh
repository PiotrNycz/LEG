# MIT License
#
# Copyright (c) 2022 Piotr Nycz
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

function compact () {
    sed -i '/include "/d' $1
    sed -i '/pragma/d' $1
    awk -f compact.awk $1 > temp.cpp
    sed -i 's/include <cassert>/define assert(x) static_cast<void>(x)/' temp.cpp
    mv temp.cpp $1
}

cat ../Color.hpp > ObjectTests.cpp
cat ../../utils/TrivialOptional.hpp >> ObjectTests.cpp
cat ../Object.hpp >> ObjectTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectTests.cpp
cat ../ObjectTests.cpp >> ObjectTests.cpp
compact ObjectTests.cpp

cat ../Quadratic.hpp > QuadraticTests.cpp
cat ../QuadraticTests.cpp >> QuadraticTests.cpp
compact QuadraticTests.cpp

cat ../../utils/IgnoreWhenCompare.hpp > QuadraticSolved1Tests.cpp
cat ../QuadraticSolved1.hpp >> QuadraticSolved1Tests.cpp
cat ../QuadraticSolved1Tests.cpp >> QuadraticSolved1Tests.cpp
compact QuadraticSolved1Tests.cpp

cat ../QuadraticSolved2.hpp > QuadraticSolved2Tests.cpp
cat ../QuadraticSolved2Tests.cpp >> QuadraticSolved2Tests.cpp
compact QuadraticSolved2Tests.cpp
