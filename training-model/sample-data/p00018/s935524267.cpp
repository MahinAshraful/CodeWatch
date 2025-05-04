#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int input[5];
  for (int input_i = 0; input_i < 5; input_i++)
    cin >> input[input_i];
  sort(input, input+5, greater<int>());
  for (int input_i = 0; input_i < 5; input_i++) {
    cout << input[input_i];
    if (input_i != 4)
      cout << " ";
  }
  cout << endl;
  return 0;
}