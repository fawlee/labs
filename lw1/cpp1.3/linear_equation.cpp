#include <cstdio>
#include <stdio.h>

int main()
{
    std::puts("please enter a and b for ` ax + b = 0`:");
    int a = 0;
    int b = 0;
    std::scanf("%d %d", &a, &b);
    // solution: `x = -b / a`
    int x = -b / a;
    std::printf("solution: %d/n", x);
}