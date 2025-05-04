#include <iostream>
#include <sstream>
#include <string>
int main()
{
  int w, n;
  std::cin >> w;
  std::cin >> n;
  int num[w + 1];
  for (int i = 1; i <= w; i++) {
    num[i] = i;
  }
  while (n--) {
    std::string line;
    std::cin >> line;
    int index = line.find(",");
    if (index != -1) line.replace(index, 1, " ");
    std::istringstream iss(line);
    int a, b, temp;
    iss >> a >> b;
    temp = num[a];
    num[a] = num[b];
    num[b] = temp;
  }
  for (int i = 1; i <= w; i++) {
    std::cout << num[i] << std::endl;
  }
  
  return 0;
}