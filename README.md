# SYNOPSIS
Counts the number of trailing zeros for an integer in binary.


# EXAMPLE

```c++
#include "deps/datcxx/cxx-count-trailing-zeros/index.hxx"
#include <iostream>

for (size_t i=1; i <= 16; ++i) {
  auto n = Hypercore::ctz(i);
  auto d = std::bitset<sizeof(i)>(i);

  cout << i
    << " (bin " << d << ") has "
    << std::to_string(n) << " trailing zeros"
    << std::endl;
}
```

```
1 (bin 0001) has 0 trailing zeros
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
```


# SEE ALSO

This is a direct port of [this][0] library.

[0]:https://github.com/mikolalysenko/count-trailing-zeros
