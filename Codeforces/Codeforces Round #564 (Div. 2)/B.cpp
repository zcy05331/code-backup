#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e3 + 10;

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (n / 2) + 1);
    int x = 1, y = 1;
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", x, y);
        if (i & 1)
            y++;
        else
            x++;
    }
    return 0;
}
