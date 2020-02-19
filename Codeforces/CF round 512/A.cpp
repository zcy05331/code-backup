#include <bits/stdc++.h>

const int MaxN = 100010;

int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i = 1, x; i <= n; i++)
        scanf("%d", &x), sum += x;
    printf(sum ? "HARD" : "EASY");
    return 0;
}