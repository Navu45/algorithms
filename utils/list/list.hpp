#if !defined(LIST_HPP)
#define LIST_HPP

#include "list.h"

generic void List<T>::connect_(Node2L<T> *node, Node2L<T> *nextNode) {
  node->next = nextNode;
  nextNode->prev = node;
}

generic void List<T>::push_back(T value) {
  Node2L<T> *currTail = this->store_->get_tail();
  this->store_->set_tail(new Node2L<T>(value));
  if (currTail != nullptr) {
    this->connect_(currTail, this->store_->get_tail());
  }
  this->store_->increment();
}

generic void List<T>::push_front(T value) {
  Node2L<T> *currHead = this->store_->get_head();
  this->store_->set_head(new Node2L(value));
  if (currHead != nullptr) {
    this->connect_(this->store_->get_head(), currHead);
  }
  this->store_->increment();
}

generic void List<T>::insert(size_t idx, T value) {
  if (idx == this->size()) {
    this->push_back(value);
  } else if (idx == 0) {
    this->push_front(value);
  } else {
    Node2L<T> *node = this->store_->index(idx);
    if (node != nullptr) {
      Node2L<T> *new_node = new Node2L<T>(value);
      this->connect_(node->prev, new_node);
      this->connect_(new_node, node);
      this->store_->increment();
    }
  }
}

generic T& List<T>::index(size_t idx) const {
  Node2L<T> *node = this->store_->index(idx);
  return node->value;
}

generic T& List<T>::operator[](size_t index) const {
  return this->index(index);
}

generic void List<T>::operator+=(T value) {
  this->push_back(value);
}

generic void List<T>::remove(size_t idx) {
  Node2L<T> *node = this->store_->index(idx);
  if (node == nullptr)
    return;
  if (node == this->store_->get_head()) {
    this->store_->set_head(node->next);
    if (node->next != nullptr)
      node->next->prev = nullptr;
  } else if (node == this->store_->get_tail()) {
    this->store_->set_tail(node->prev);
    if (node->prev != nullptr)
      node->prev->next = nullptr;
  } else {
    this->connect_(node->prev, node->next);
  }
  delete node;
  this->store_->decrement();

  if (this->empty()) {
    this->store_->set_head(nullptr);
    this->store_->set_tail(nullptr);
  }
}

generic void List<T>::update(size_t idx, T value) {
  Node2L<T> *node = this->store_->index(idx);
  if (node != nullptr) {
    this->store_->set_node(node, value);
  }
}

generic size_t List<T>::size() const { return this->store_->get_size(); }

generic bool List<T>::empty() const { return this->store_->get_size() == 0; }

generic void List<T>::print() const { this->store_->print(); }

#endif // LIST_HPP