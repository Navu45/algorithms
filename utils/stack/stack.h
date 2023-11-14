#if !defined(STACK_H)
#define STACK_H

#include "../container/container.h"

generic class Node1L {
public:
  T value;
  Node1L *next;

  Node1L(T value) : value(value), next(nullptr) {}
  Node1L(T value, Node1L *next) : value(value), next(next) {}
};

generic class Stack : public IExtend<T, Node1L<T>> {
private:
  void connect_(Node1L<T> *node, Node1L<T> *nextNode);

public:
  void push(T value);
  T top() const;
  void pop();
  void print() const;
};

#include "stack.hpp"

#endif // STACK_H
