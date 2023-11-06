#if !defined(EXTEND_H)
#define EXTEND_H

#include <iostream>
using namespace std;

#if !defined(GENERIC)
#define GENERIC

#define gen_container template <typename T, class N>
#define generic template <typename T>

#endif // GENERIC

template <typename T, class N> class Container {

  // class N must have fields "value" of type T and "next"
  // and constructor N(T value)
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

  N *get_head() const;
  N *get_tail() const;

  N *index(size_t idx);

  void increment();
  void decrement();
  size_t get_size() const;

  void print() const;

private:
  N *head_;
  N *tail_;
  size_t size_;

  N *index_(N *node, size_t curr_idx, size_t target_idx);
};

#include "container.hpp"

gen_container class IExtend {
protected:
  Container<T, N> *store_;

public:
  IExtend() { this->store_ = new Container<T, N>(); }
  ~IExtend() { delete this->store_; }
};

#endif // EXTEND_H
