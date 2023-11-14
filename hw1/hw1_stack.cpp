#include "../utils/stack/stack.h"

int main() {
  Stack<int> stack;
  int in, n;
  cin >> n;

  // Push
  for (size_t i = 0; i < n; i++) {
    cin >> in;
    stack.push(in);
  }
  stack.print();

  //
  cout << "Top: " << stack.top() << endl;

  // Pop
  stack.pop();
  stack.print();
}
