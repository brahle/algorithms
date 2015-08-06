#ifndef BRAHLE_ALGORITHMS_MATH_PRIMES
#define BRAHLE_ALGORITHMS_MATH_PRIMES

#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

namespace math {

class PrimalityTestingException : public std::runtime_error {
public:
  PrimalityTestingException(const char* msg) : std::runtime_error(msg) {}
};

template <typename T>
class PrimalityTesting {
public:
  static bool isPrimeDumb(const T &x)
    noexcept(std::is_nothrow_copy_constructible<T>::value) {
    if (x < 2) return false;
    for (T t = 2; t * t <= x; ++t) {
      if (x % t == 0) {
        return false;
      }
    }
    return true;
  }

  bool isPrimeUsingArray(const T &x) const noexcept(false) {
    if (x < 2) return false;
    size_t i = 0;
    for (i = 0; i < primes_.size(); ++i) {
      if (primes_[i] * primes_[i] > x) {
        return true;
      }
      if (x % primes_[i] == 0) {
        return false;
      }
    }
    throw PrimalityTestingException(
      "Prime array not large enough. Have you precomputed it?"
    );
  }

  template <typename T2 = bool>
  void generatePrimes(const T &limit) noexcept(false) {
    static_assert(
      std::is_default_constructible<T2>::value,
      "PrimalityTesting::generatePrimes requires secondary type to be "
      "default-constructible"
    );
    primes_.clear();
    primes_.reserve(limit / (log(limit) - 1));

    std::vector< T2 > table(limit+1, 0);

    for (T i = 2; i <= limit; ++i) {
      if (table[i] != 0) {
        continue;
      }
      primes_.emplace_back(i);
      for (T j = i + i; j <= limit; j += i) {
        table[j] = 1;
      }
    }
  }

private:
  std::vector< T > primes_;

  static_assert(
    std::is_arithmetic<T>::value,
    "PrimalityTesting requires elements that implement basic operations"
  );

  static_assert(
    std::is_copy_constructible<T>::value,
    "PrimalityTesting requires copy-constructible elements"
  );
};

}

#endif
