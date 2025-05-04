#include <iostream>
using namespace std;

void calcGCDLCM(unsigned int in1, unsigned int in2,
    unsigned int* GCD, unsigned int* LCM) {
  unsigned int num1, num2;
  unsigned int denom=2;
  unsigned int tempGCD=1;

  if(in1>in2) {
    num1=in2;
    num2=in1;
  } else {
    num1=in1;
    num2=in2;
  }

  while(denom <= num1) {
    if(num1 % denom == 0 && num2 % denom == 0) {
      tempGCD *= denom;
      num1 /= denom;
      num2 /= denom;
    } else {
      denom++;
    }
  }

  *GCD = tempGCD;
  *LCM = tempGCD*num1*num2;
}

int main() {
  unsigned int in1, in2;
  unsigned int GCD, LCM;

  while(cin >> in1 >> in2) {
    calcGCDLCM(in1,in2,&GCD,&LCM);
    cout << GCD << " " << LCM << endl;
  }
  return 0;
}