#include "list/list.h"

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
  list.remove(in);
  list.print();

  // Replace element
  cout << "Replace: ";
  int in1;
  cin >> in >> in1;
  list.update(in, in1);
  list.print();
  
  // Insert element
  cout << "Insert: ";
  cin >> in >> in1;
  list.insert(in, in1);
  list.print();
}
