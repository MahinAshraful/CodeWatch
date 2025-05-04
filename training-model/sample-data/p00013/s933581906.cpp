#include <cstdio>
#include <stack>

using namespace std;

int main() {
    stack<int> q;
    while (true) {
        int n;
        if (scanf("%d", &n) == EOF)
            break;

        if (n) {
            q.push(n);
        } else {
            printf("%d\n", q.top());
            q.pop();
        }
    }

    return 0;
}