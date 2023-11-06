#if !defined(EXTEND_H)
#define EXTEND_H

#include <iostream>

template <typename T, class N> class Container {
public:
  Container();
  ~Container();

public:
  void set_node(N *node, T value);
  void del_node(N *node);

  void set_head(T value);
  void set_tail(T value);

  void set_head(N *node);
  void set_tail(N *node);

  N *get_head();
  N *get_tail();

  N *index(size_t idx);

  void increment();
  void decrement();
  size_t get_size();

private:
  N *head_;
  N *tail_;
  size_t size_;

  N *index_(N *node, size_t curr_idx, size_t target_idx);
};

#include "container.hpp"

#endif // EXTEND_H
