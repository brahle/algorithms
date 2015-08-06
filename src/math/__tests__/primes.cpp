#include <cassert>
#include <cstdint>
#include <iostream>

#include <math/primes.h>

using PrimalityTesting = math::PrimalityTesting <uint64_t>;

int main() {
  assert(!PrimalityTesting::isPrimeDumb(0));
  assert(!PrimalityTesting::isPrimeDumb(1));
  assert(PrimalityTesting::isPrimeDumb(2));
  assert(PrimalityTesting::isPrimeDumb(3));
  assert(!PrimalityTesting::isPrimeDumb(4));
  assert(PrimalityTesting::isPrimeDumb(5));
  assert(!PrimalityTesting::isPrimeDumb(6));
  assert(PrimalityTesting::isPrimeDumb(7));
  assert(!PrimalityTesting::isPrimeDumb(8));
  assert(!PrimalityTesting::isPrimeDumb(9));
  assert(!PrimalityTesting::isPrimeDumb(10));
  assert(!PrimalityTesting::isPrimeDumb(10));
  assert(PrimalityTesting::isPrimeDumb(997));
  assert(PrimalityTesting::isPrimeDumb(8425171));
  assert(PrimalityTesting::isPrimeDumb(1120474079LL));
  assert(PrimalityTesting::isPrimeDumb(21500523123449LL));
  assert(!PrimalityTesting::isPrimeDumb(11852251LL * 11852263LL));

  uint64_t n = 1000;
  PrimalityTesting t;
  t.generatePrimes(n + 1000);

  for (uint64_t x = 0; x < (n-1)*(n-1); ++x) {
    if (PrimalityTesting::isPrimeDumb(x) != t.isPrimeUsingArray(x)) {
      std::cout << "Fail for " << x << std::endl;
      std::cout << "isPrimeDumb = " << PrimalityTesting::isPrimeDumb(x)
        << std::endl;
      std::cout << "isPrimeUsingArray = "
        << t.isPrimeUsingArray(x) << std::endl;
      return 1;
    }
  }

  return 0;
}
