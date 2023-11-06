#if !defined(LIST_H)
#define LIST_H

#include "../container/container.h"
#include <iostream>
using namespace std;

template <typename T> class Node2L {
public:
  T value;
  Node2L *next;
  Node2L *prev;

  Node2L(T value) : value(value), next(nullptr), prev(nullptr) {}

  Node2L(T value, Node2L *next) : value(value), next(next) {}

  Node2L(T value, Node2L *next, Node2L *prev)
      : value(value), next(next), prev(prev) {}
};

template <typename T> class List {
private:
  Container<T, Node2L<T>> *list_;

  void connect_(Node2L<T> *node, Node2L<T> *nextNode);

public:
  List();
  ~List();
  void push_back(T value);
  void push_front(T value);
  void remove(size_t idx);
  void update(size_t idx, T value);
  void insert(size_t idx, T value);
  T index(size_t idx) const;
  bool empty() const;
  size_t size() const;
  void print() const;
};

#include "list.hpp"

#endif // LIST_H