#include "../index.hxx"
#include "../deps/heapwolf/cxx-tap/index.hxx"

#include <iostream>
#include <sstream>

int main() {
  TAP::Test t;

  t.test("sanity", [](auto t) {
    t->ok(true, "true is true");
    t->end();
  });

  t.test("ctz", [] (auto t) {
    t->equal(Hypercore::ctz(0), 32);
    t->equal(Hypercore::ctz(1), 0);
    t->equal(Hypercore::ctz(-1), 0);

    for (size_t i=0; i < 31; ++i) {
      t->equal(Hypercore::ctz(1<<i), i);

      if (i > 0) {
        t->equal(Hypercore::ctz((1<<i)-1), 0);
      }
    }

    t->equal(Hypercore::ctz(0xf81700), 8);
    t->end();
  });

  t.test("readme example", [] (auto t) {

    std::string expected = R"(1 (bin 0001) has 0 trailing zeros
2 (bin 0010) has 1 trailing zeros
3 (bin 0011) has 0 trailing zeros
4 (bin 0100) has 2 trailing zeros
5 (bin 0101) has 0 trailing zeros
6 (bin 0110) has 1 trailing zeros
7 (bin 0111) has 0 trailing zeros
8 (bin 1000) has 3 trailing zeros
9 (bin 1001) has 0 trailing zeros
10 (bin 1010) has 1 trailing zeros
11 (bin 1011) has 0 trailing zeros
12 (bin 1100) has 2 trailing zeros
13 (bin 1101) has 0 trailing zeros
14 (bin 1110) has 1 trailing zeros
15 (bin 1111) has 0 trailing zeros
16 (bin 0000) has 4 trailing zeros
)";

    std::stringstream ss;

    for (int i=1; i <= 16; ++i) {
      auto n = Hypercore::ctz(i);
      auto d = std::bitset<sizeof(i)>(i);

      ss << i
        << " (bin " << d << ") has "
        << std::to_string(n) << " trailing zeros"
        << std::endl;
    }

    t->equal(expected, ss.str(), "strings match");
    t->end();
  });
}
