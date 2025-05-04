#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int NMAX = 10000;

void PrintArray(int* A, int N)
{
   cout << A[0]; 
   for (int k = 1; k < N;k++) {
     cout << " " << A[k] ; 
   }
   cout << endl;
}
void Swap(int& a, int &b) {
  int tmpA, tmpB;
  tmpA = a;
  tmpB = b;
  a = tmpB;
  b = tmpA;
}

int selectionSort(int* A, int N){
  int count = 0;
  for (int i = 0; i < N - 1; i++){
    int minj = i;
    for (int j = i+1; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    Swap(A[i], A[minj]);
    if (i != minj) { 
      count += 1;
    }
  }
  return count;
} 


int main()
{
  int A[10];
  for (int i = 0; i< 10; i++) {
    int x; 
    cin >> x; 
    A[i] = x;
  } 
  selectionSort(A,10);
  for (int i = 0; i< 3; i++) {
    cout << A[9 -i] << endl; 
  } 
  return 0;
}