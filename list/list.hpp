#if !defined(LIST_HPP)
#define LIST_HPP

#include "list.h"

#define generic template <typename T>

generic List<T>::List() { this->list_ = new Container<T, Node2L<T>>(); }
generic List<T>::~List() { delete this->list_; }

generic void List<T>::connect_(Node2L<T> *node, Node2L<T> *nextNode) {
  node->next = nextNode;
  nextNode->prev = node;
}

generic void List<T>::push_back(T value) {
  Node2L<T> *currTail = this->list_->get_tail();
  this->list_->set_tail(new Node2L<T>(value));
  if (currTail != nullptr) {
    this->connect_(currTail, list_->get_tail());
  }
  this->list_->increment();
}

generic void List<T>::push_front(T value) {
  Node2L<T> *currHead = this->list_->get_head();
  this->list_->set_head(new Node2L(value));
  if (currHead != nullptr) {
    this->connect_(list_->get_head(), currHead);
  }
  this->list_->increment();
}

generic void List<T>::insert(size_t idx, T value) {
  if (idx == this->size()) {
    this->push_back(value);
  } else if (idx == 0) {
    this->push_front(value);
  } else {
    Node2L<T> *node = this->list_->index(idx);
    if (node != nullptr) {
      Node2L<T> *new_node = new Node2L<T>(value);
      this->connect_(node->prev, new_node);
      this->connect_(new_node, node);
      this->list_->increment();
    }
  }
}

generic void List<T>::remove(size_t idx) {
  Node2L<T> *node = this->list_->index(idx);
  if (node == nullptr)
    return;
  if (node->prev == nullptr) {
    this->list_->set_head(node->next);
    node->next->prev = nullptr;
  } else if (node->next == nullptr) {
    this->list_->set_tail(node->prev);
    node->prev->next = nullptr;
  } else {
    this->connect_(node->prev, node->next);
  }
  delete node;
  this->list_->decrement();
}

generic void List<T>::update(size_t idx, T value) {
  Node2L<T> *node = this->list_->index(idx);
  if (node != nullptr) {
    this->list_->set_node(node, value);
  }
}

generic size_t List<T>::size() const { return this->list_->get_size(); }

generic bool List<T>::empty() const { return this->list_->get_size() == 0; }

generic void List<T>::print() {
  Node2L<T> *curr_node = this->list_->get_head();
  cout << "[ ";
  while (curr_node != nullptr) {
    cout << curr_node->value << (curr_node->next != nullptr ? ", " : "");
    curr_node = curr_node->next;
  }
  cout << " ]" << endl;
}

#endif // LIST_HPP