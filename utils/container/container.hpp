#if !defined(EXTEND_HPP)
#define EXTEND_HPP

#include "container.h"

gen_container void Container<T, N>::set_node(N *node, T value) {
  if (node == this->head_)
    this->set_head(value);
  else if (node != nullptr)
    node->value = value;
}

gen_container void Container<T, N>::set_head(T value) {
  if (this->head_ == nullptr) {
    this->head_ = new N(value);
    this->tail_ = this->head_;
  } else {
    this->head_->value = value;
  }
}

gen_container void Container<T, N>::set_tail(T value) {
  if (this->tail_ == nullptr) {
    this->tail_ = new N(value);
    this->head_ = this->tail_;
  } else {
    this->tail_->value = value;
  }
}

gen_container void Container<T, N>::set_head(N *node) {
  this->head_ = node;
  if (this->tail_ == nullptr) {
    this->tail_ = this->head_;
  }
}

gen_container void Container<T, N>::set_tail(N *node) {
  this->tail_ = node;
  if (this->head_ == nullptr) {
    this->head_ = this->tail_;
  }
}

gen_container N *Container<T, N>::get_head() const { return this->head_; }

gen_container N *Container<T, N>::get_tail() const { return this->tail_; }

gen_container void Container<T, N>::del_node(N *node) {
  if (node == nullptr)
    return;
  N *next_node = node->next;
  delete node;
  this->del_node(next_node);
}

gen_container N *Container<T, N>::index_(N *node, size_t curr_idx,
                                         size_t target_idx) {
  if (curr_idx == target_idx) {
    return node;
  } else {
    return this->index_(node->next, curr_idx + 1, target_idx);
  }
}

gen_container N *Container<T, N>::index(size_t idx) {
  return idx < this->size_ ? this->index_(this->head_, 0, idx) : nullptr;
}

gen_container void Container<T, N>::increment() { this->size_++; }

gen_container void Container<T, N>::decrement() { this->size_--; }

gen_container size_t Container<T, N>::get_size() const { return this->size_; }

gen_container Container<T, N>::~Container() { this->del_node(this->head_); }

gen_container Container<T, N>::Container() {
  this->head_ = nullptr;
  this->tail_ = nullptr;
  this->size_ = 0;
}

template <typename N> void print_(N *node) {
  cout << node->value << (node->next != nullptr ? ", " : "");
  if (node->next != nullptr)
    print_(node->next);
}

gen_container void Container<T, N>::print() const {
  N *curr_node = this->get_head();
  cout << "[";
  print_(curr_node);
  cout << "]" << endl;
}

#endif // EXTEND_HPP
