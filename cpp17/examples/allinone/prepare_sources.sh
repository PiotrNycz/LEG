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

cat ../Color.hpp > ObjectSimpleTests.cpp
cat ../ObjectSimple.hpp >> ObjectSimpleTests.cpp
cat ../ColorSimpleCompare.hpp >> ObjectSimpleTests.cpp
cat ../ObjectSimpleCompare.hpp >> ObjectSimpleTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectSimpleTests.cpp
cat ../ObjectSimpleTests.hpp >> ObjectSimpleTests.cpp
cat ../ObjectSimpleTests.cpp >> ObjectSimpleTests.cpp
compact ObjectSimpleTests.cpp

cat ../Color.hpp > ObjectSimpleAsTupleTests.cpp
cat ../ObjectSimple.hpp >> ObjectSimpleAsTupleTests.cpp
cat ../ColorAsTupleCompare.hpp >> ObjectSimpleAsTupleTests.cpp
cat ../../utils/MakeOptionalRef.hpp >> ObjectSimpleAsTupleTests.cpp
cat ../ObjectSimpleAsTupleCompare.hpp >> ObjectSimpleAsTupleTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectSimpleAsTupleTests.cpp
cat ../ObjectSimpleTests.hpp >> ObjectSimpleAsTupleTests.cpp
cat ../ObjectSimpleAsTupleTests.cpp >> ObjectSimpleAsTupleTests.cpp
compact ObjectSimpleAsTupleTests.cpp

cat ../Color.hpp > ObjectAsTupleTests.cpp
cat ../../utils/TrivialOptional.hpp >> ObjectAsTupleTests.cpp
cat ../Object.hpp >> ObjectAsTupleTests.cpp
cat ../ColorAsTupleCompare.hpp >> ObjectAsTupleTests.cpp
cat ../ObjectAsTupleCompare.hpp >> ObjectAsTupleTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectAsTupleTests.cpp
cat ../ObjectTests.hpp >> ObjectAsTupleTests.cpp
cat ../ObjectAsTupleTests.cpp >> ObjectAsTupleTests.cpp
compact ObjectAsTupleTests.cpp

cat ../Color.hpp > ObjectDoubleApplyTests.cpp
cat ../../utils/TrivialOptional.hpp >> ObjectDoubleApplyTests.cpp
cat ../../utils/IsEqual.hpp >> ObjectDoubleApplyTests.cpp
cat ../../utils/Spaceship.hpp >> ObjectDoubleApplyTests.cpp
cat ../Object.hpp >> ObjectDoubleApplyTests.cpp
cat ../ColorDoubleApplyCompare.hpp >> ObjectDoubleApplyTests.cpp
cat ../ObjectDoubleApplyCompare.hpp >> ObjectDoubleApplyTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectDoubleApplyTests.cpp
cat ../ObjectTests.hpp >> ObjectDoubleApplyTests.cpp
cat ../ObjectDoubleApplyTests.cpp >> ObjectDoubleApplyTests.cpp
compact ObjectDoubleApplyTests.cpp

cat ../Color.hpp > ObjectDoubleApplyMacrosTests.cpp
cat ../../utils/TrivialOptional.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../../utils/IsEqual.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../../utils/Spaceship.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../../utils/DoubleApplyMacros.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../Object.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../ColorDoubleApplyMacrosCompare.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../ObjectDoubleApplyMacrosCompare.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../ObjectTests.hpp >> ObjectDoubleApplyMacrosTests.cpp
cat ../ObjectDoubleApplyMacrosTests.cpp >> ObjectDoubleApplyMacrosTests.cpp
compact ObjectDoubleApplyMacrosTests.cpp

cat ../Color.hpp > ObjectSimpleMacrosTests.cpp
cat ../../utils/TrivialOptional.hpp >> ObjectSimpleMacrosTests.cpp
cat ../../utils/SimpleCompareMacros.hpp >> ObjectSimpleMacrosTests.cpp
cat ../Object.hpp >> ObjectSimpleMacrosTests.cpp
cat ../ColorSimpleMacrosCompare.hpp >> ObjectSimpleMacrosTests.cpp
cat ../ObjectSimpleMacrosCompare.hpp >> ObjectSimpleMacrosTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectSimpleMacrosTests.cpp
cat ../ObjectTests.hpp >> ObjectSimpleMacrosTests.cpp
cat ../ObjectSimpleMacrosTests.cpp >> ObjectSimpleMacrosTests.cpp
compact ObjectSimpleMacrosTests.cpp

cat ../Color.hpp > ObjectMacrosTests.cpp
cat ../../utils/TrivialOptional.hpp >> ObjectMacrosTests.cpp
cat ../../utils/CompareMacros.hpp >> ObjectMacrosTests.cpp
cat ../Object.hpp >> ObjectMacrosTests.cpp
cat ../ColorMacrosCompare.hpp >> ObjectMacrosTests.cpp
cat ../ObjectMacrosCompare.hpp >> ObjectMacrosTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectMacrosTests.cpp
cat ../ObjectTests.hpp >> ObjectMacrosTests.cpp
cat ../ObjectMacrosTests.cpp >> ObjectMacrosTests.cpp
compact ObjectMacrosTests.cpp

cat ../Color.hpp > ObjectFusionTests.cpp
cat ../../utils/TrivialOptional.hpp >> ObjectFusionTests.cpp
cat ../Object.hpp >> ObjectFusionTests.cpp
cat ../ColorFusionCompare.hpp >> ObjectFusionTests.cpp
cat ../ObjectFusionCompare.hpp >> ObjectFusionTests.cpp
cat ../../utils/TestUtils.hpp >> ObjectFusionTests.cpp
cat ../ObjectTests.hpp >> ObjectFusionTests.cpp
cat ../ObjectFusionTests.cpp >> ObjectFusionTests.cpp
compact ObjectFusionTests.cpp
