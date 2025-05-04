#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    char a[30];
    char b[30];
    gets(a);
    int count = 0;
    for (int i=0; a[i]; i++)
    {
        count ++;
    }
    int i;
    for (i=0; count != 0; i++)
    {
        b[i] = a[--count];
    }
    b[i] = '\0';
    puts(b);
    return 0;
}