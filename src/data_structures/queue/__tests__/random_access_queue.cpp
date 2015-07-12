#include <cassert>
#include <cstdio>
#include <cstdint>
#include <iostream>

#include <macros/debug.h>
#include <data_structures/queue/random_access_queue.h>

#ifdef DEBUG
#define EFINE_N 5
#define EFINE_ROUNDS 3
#else
#define EFINE_N 100000
#define EFINE_ROUNDS 10000
#endif

const uint32_t N = EFINE_N;
const uint32_t ROUNDS = EFINE_ROUNDS;

template <class T, size_t size>
using Queue =
  data_structures::
    queue::
      RandomAccessQueue <T, size, size>;

using UIntQueue = Queue <uint32_t, N>;

inline void enque(UIntQueue &Q, const uint32_t length = N) {
  for (uint32_t a = 0; a != length; ++a) {
    Q.push(a);
  }
}

inline void random_access(UIntQueue &Q, const uint32_t length = N) {
  for (uint32_t a = 0; a != length; ++a) {
    assert(Q[a] == a);
  }
}

inline void deque(UIntQueue &Q, const uint32_t length = N) {
  for (uint32_t a = 0; a != length; ++a) {
    auto front = Q.front();
    assert(front == a);
    auto pop = Q.pop();
    assert(pop == a);
  }
}

int main() {
  DEBUG_PRINT("creating QUEUE");
  UIntQueue Q;
  DEBUG_PRINT("QUEUE created!");

  for (uint32_t rounds = 0; rounds < ROUNDS; ++rounds) {
    enque(Q);
    random_access(Q);
    deque(Q);
  }

  return 0;
}
