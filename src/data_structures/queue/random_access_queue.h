#ifndef BRAHLE_ALGORITHMS_DATA_STRUCTURES_QUEUE_RANDOM_ACCESS_QUEUE
#define BRAHLE_ALGORITHMS_DATA_STRUCTURES_QUEUE_RANDOM_ACCESS_QUEUE

#include <array>
#include <cassert>
#include <cstdint>

#include <macros/debug.h>

namespace data_structures {
namespace queue {

template <class T, size_t size> using array = std::array <T, size>;

template <
  typename T,
  size_t size,
  size_t extra = size,
  typename Alloc = array<T, size + extra> >
class RandomAccessQueue : private Alloc {

public:
  RandomAccessQueue() : left_(0), right_(0) {}

  void push(const T &x) {
    DEBUG_PRINT("::push %d\n", x);
    this->Alloc::operator[](right_) = x;
    DEBUG_PRINT("moving RIGHT pointer.\n");
    ++right_ %= size;
    DEBUG_PRINT("RIGHT is now %d\n", right_);
  }

  const T& pop() {
    DEBUG_PRINT("::pop\n");
    size_t old_left = left_;
    DEBUG_PRINT("LEFT is %d\n", old_left);
    DEBUG_PRINT("DATA is %d\n", this->Alloc::operator[](old_left));
    left_ = (left_ + 1) % size;
    DEBUG_PRINT("LEFT is now %d\n", left_);
    return this->Alloc::operator[](old_left);
  }

  const T& front() {
    DEBUG_PRINT("::front\n");
    DEBUG_PRINT("LEFT is %d\n", left_);
    DEBUG_PRINT("DATA is %d\n", this->Alloc::operator[](left_));
    return this->Alloc::operator[](left_);
  }

  const T& operator[](const size_t &i) const {
    DEBUG_PRINT("::[%d] (const)\n", i);
    DEBUG_PRINT("LEFT is %d, LEFT + i = %d\n", left_, (left_ + i) % size);
    DEBUG_PRINT("DATA is %d\n", this->Alloc::operator[]((left_ + i) % size));
    return this->Alloc::operator[]((left_ + i) % size);
  }

  T& operator[](const size_t &i) {
    DEBUG_PRINT("::[%d]\n", i);
    DEBUG_PRINT("LEFT is %d, LEFT + i = %d\n", left_, (left_ + i) % size);
    DEBUG_PRINT("DATA is %d\n", this->Alloc::operator[]((left_ + i) % size));
    return this->Alloc::operator[]((left_ + i) % size);
  }

private:
  size_t left_;
  size_t right_;

};

}
}

#endif
