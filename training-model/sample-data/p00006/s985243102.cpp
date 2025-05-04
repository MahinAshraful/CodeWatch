#include <iostream>
using namespace std;

int main(void)
{
  int i;
  char str[21];
  cin >> str;
  
  for(i = 0; str[i] != '\0'; i++){
  }

  int j;
  char ans[21];

  for(j = 0; j < i; j++){
    ans[j] = str[i-j-1];
  }
  ans[j] = '\0';

  cout << ans << endl;

  return 0;
}