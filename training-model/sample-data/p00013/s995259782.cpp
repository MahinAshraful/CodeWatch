//外積を使う

#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>

using namespace std;


int main(){
	
	vector<int> stack;

	int i = 0;
	int ret;

	while (scanf("%d", &ret) != EOF){
		if (ret != 0){
			stack.push_back(ret);
		}
		else{
			cout << stack[stack.size()-1]<< endl;
			stack.pop_back();
		}
	}


	return 0;
}