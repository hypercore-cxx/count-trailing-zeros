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

      if (i > 0) t->equal(Hypercore::ctz((1<<i)-1), 0);
    }

    t->equal(Hypercore::ctz(0xf81700), 8);
    t->end();
  });
}
