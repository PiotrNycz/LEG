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
#include <cstdint>
#include <tuple>
#include <functional>
#include <boost/functional/hash.hpp>
#include <cassert>
#include <boost/fusion/include/hash.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

template <int N>
struct Color {
    uint16_t r, g, b;
};

// simple
namespace std {
template <> struct hash<Color<1>> {
    size_t operator()(const Color<1>& c) const {
        size_t res = 0;
        boost::hash_combine(res, c.r);
        boost::hash_combine(res, c.g);
        boost::hash_combine(res, c.b);
        return res;
    }
};
}

// tuple
inline auto tieMembers(const Color<2>& c) {
    return std::tie(c.r, c.g, c.b);
}

namespace std {
template <> struct hash<Color<2>> {
    size_t operator()(const Color<2>& c) const {
        return boost::hash_value(tieMembers(c));
    }
};
}

// apply
template <typename F>
inline auto apply(const F& f, const Color<3>& c) {
    return f(c.r, c.g, c.b);
}

struct HashCombiner {
    template <typename ...T>
    size_t operator()(const T& ...v) const {
        size_t seed=0;
        ((void)boost::hash_combine(seed, v), ...);
        return seed;
    }
};


namespace std {
template <> struct hash<Color<3>> {
    size_t operator()(const Color<3>& c) const {
        return ::apply(HashCombiner{}, c);
    }
};
}

// fusion
using Color4 = Color<4>;
BOOST_FUSION_ADAPT_STRUCT(Color4, r, g, b)

namespace std {
template <> struct hash<Color<4>> {
    size_t operator()(const Color<4>& c) const {
        return boost::fusion::hash_value(c);
    }
};
}



int main() {
    assert(std::hash<Color<1>>{}(Color<1>{1,2,3}) == std::hash<Color<2>>{}(Color<2>{1,2,3}));
    assert(std::hash<Color<1>>{}(Color<1>{1,2,3}) == std::hash<Color<3>>{}(Color<3>{1,2,3}));
    assert(std::hash<Color<1>>{}(Color<1>{1,2,3}) == std::hash<Color<4>>{}(Color<4>{1,2,3}));
}
