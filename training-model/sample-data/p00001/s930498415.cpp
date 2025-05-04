#include <algorithm>
#include <cstdio>
#include <functional>

using namespace std;

int main(){
    int height[10];
    for(int i = 0; i < 10; i++){
        scanf("%d", &height[i]);
    }

    sort(height, height + 10, greater<int>());

    printf("%d\n%d\n%d\n", height[0], height[1], height[2]);
    return 0;

}