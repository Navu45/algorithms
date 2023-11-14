#if !defined(STACK_HPP)
#define STACK_HPP

#include "stack.h"

generic void Stack<T>::push(T value) {
  Node1L<T> *currHead = this->store_->get_head();
  this->store_->set_head(new Node1L(value));
  if (currHead != nullptr) {
    this->store_->get_head()->next = currHead;
  }
}

generic T Stack<T>::top() const {
  Node1L<T> *node = this->store_->get_head();
  return node != nullptr ? node->value : INT_MAX;
}

generic void Stack<T>::pop() {
  Node1L<T> *currHead = this->store_->get_head();
  if (currHead != nullptr) {
    this->store_->set_head(currHead->next);
    T result = currHead->value;
    delete currHead;
  }
}

generic void Stack<T>::print() const { this->store_->print(); }

#endif // STACK_HPP
