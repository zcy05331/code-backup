#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a = 1, b = 1, c = n - 2;
    if(c % 3 != 0)
        printf("%d %d %d\n", a, b, c);
    else
    {
        printf("%d %d %d\n", a + 1, b, c - 1);
    }
    return 0;
}