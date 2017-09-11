/* linked list */
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
  string input, token;
  list<string> output;
  bool front;
  int flag, num;
  while (cin >> input) {
    // initialize
    front = flag = num = 0;
    output.clear();
    while (flag + num < input.length()) {
      if (input[flag + num] == '[' || input[flag + num] == ']') {
        if (num) {
          token = input.substr(flag, num);
          front ? output.push_front(token) : output.push_back(token);
        }
        front = input[flag + num] == '[';
        flag = flag + num + 1;
        num = 0;
      } else {
        ++num;
      }
    }
    token = input.substr(flag, num);
    front ? output.push_front(token) : output.push_back(token);
    for (list<string>::iterator it = output.begin(); it != output.end(); ++it) {
      cout << *it;
    }
    cout << endl;
  }
  return 0;
}
