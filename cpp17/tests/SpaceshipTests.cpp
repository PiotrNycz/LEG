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

#include "Spaceship.hpp"
#include <cassert>
#include <string>

int main() {
    using namespace std::string_literals;
    assert(spaceship()() == 0);

    assert(spaceship(13)(13) == 0);
    assert(spaceship(11)(13) < 0);
    assert(spaceship(13)(11) > 0);

    assert(spaceship(1, 2.2, "a"s)(1, 2.2, "a"s) == 0);

    assert(spaceship(1, 2.2, "a"s)(2, 2.2, "a"s) < 0);
    assert(spaceship(1, 2.2, "a"s)(1, 3.3, "a"s) < 0);
    assert(spaceship(1, 2.2, "a"s)(1, 2.2, "b"s) < 0);
    assert(spaceship(1, 2.2, "a"s)(2, 3.3, "b"s) < 0);

    assert(spaceship(2, 2.2, "a"s)(1, 2.2, "a"s) > 0);
    assert(spaceship(1, 3.3, "a"s)(1, 2.2, "a"s) > 0);
    assert(spaceship(1, 2.2, "b"s)(1, 2.2, "a"s) > 0);
    assert(spaceship(2, 3.3, "b"s)(1, 2.2, "a"s) > 0);

    auto test = spaceshipByValue(1, 2.2, "a"s);
    assert(test(1, 2.2, "a"s) == 0);
    assert(test(2, 3.3, "b"s) < 0);
    assert(test(-1, -3.3, ""s) > 0);
}
