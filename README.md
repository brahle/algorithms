# Algorithms

Implementations of certain algorithms and data structures.

## Authors

Bruno Rahle

## Queue with Random Access

### Creation

To get you started, you can use something like this

```lang=cpp
#include <data_structures/queue/random_access_queue.h>

template <class T, size_t size>
using Queue =
  data_structures::
    queue::
      RandomAccessQueue <T, size, size>;

using UIntQueue = Queue <uint32_t, N>;

UIntQueue Q;
```

### Operations

* `void push(T x)` - adds the element to the queue
* `T pop()` - returns the front element from the queue and removes it
* `T front()` - returns the front element from the queue
* `const T& operator[](size_t i) const` - returns the i-th element from the queue, const version
* `T& operator[]` - returns the i-th element from the queue

All operations are O(1) time, and it uses O(N) memory.

### Testing

Run `make src\-C src\data_structures\queue\__tests__` or `make -C src\data_structures\queue\__tests__ random_access_queue_debug`
