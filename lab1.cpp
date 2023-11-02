#include <iostream>

using namespace std;

template <class T> class List {
private:
  class Node {
  public:
    T value;
    Node *next;

    Node(T value, Node *next) : value(value), next(next) {}
    Node(T value) : value(value), next(nullptr) {}
  };

  size_t size_;
  Node *head_;
  Node *tail_;

  Node *find_(size_t idx) const {
    Node *currNode = this->head_;
    for (size_t i = 0; i < idx; i++) {
      currNode = currNode->next;
    }
    return currNode;
  }

public:
  List() {
    this->size_ = 0;
    this->head_ = nullptr;
    this->tail_ = nullptr;
  }

  ~List() {
    Node *currNode = this->head_, *temp;
    while (currNode != nullptr) {
      temp = currNode;
      currNode = currNode->next;
      delete temp;
    }
  }

  void push_back(T value) {
    if (this->tail_ == nullptr) {
      this->tail_ = new Node(value);
      this->head_ = this->tail_;
    } else {
      this->tail_->next = new Node(value);
      this->tail_ = this->tail_->next;
    }
    this->size_ += 1;
  }
  void push_front(T value) {
    this->head_ = new Node(value, this->head_);
    if (this->tail_ == nullptr) {
      this->tail_ = this->head_;
    }
    this->size_ += 1;
  }

  void pop(size_t idx) {
    Node *currNode = this->head_, *prevNode = nullptr;
    for (size_t i = 0; i < idx; i++) {
      prevNode = currNode;
      currNode = currNode->next;
    }
    if (currNode != nullptr) {
      if (prevNode == nullptr)
        this->head_ = currNode->next;
      else
        prevNode->next = currNode->next;
      if (currNode == this->tail_) {
        this->tail_ = prevNode;
      }
      delete currNode;
      this->size_ -= 1;
    }
  }

  void update(size_t idx, T value) {
    Node *currNode = this->find_(idx);
    if (currNode != nullptr) {
      currNode->value = value;
    }
  }

  size_t size() const { return this->size_; }

  bool isEmpty() const { return this->size_ == 0; }

  void print() {
    Node *currNode = this->head_;
    cout << "[ ";
    while (currNode != nullptr) {
      cout << currNode->value << (currNode->next != nullptr ? ", " : "");
      currNode = currNode->next;
    }
    cout << " ]" << endl;
  }
};

int main() {
  List<int> list;
  int in, n;
  cin >> n;

  // Push to front
  for (size_t i = 0; i < n; i++) {
    cin >> in;
    list.push_front(in);
  }

  // Push to back
  for (size_t i = 0; i < n; i++) {
    cin >> in;
    list.push_back(in);
  }
  list.print();

  // Remove element
  cout << "Remove: ";
  cin >> in;
  list.pop(in);
  list.print();

  // Replace element
  cout << "Replace: ";
  int in1;
  cin >> in >> in1;
  list.update(in, in1);
  list.print();
}
