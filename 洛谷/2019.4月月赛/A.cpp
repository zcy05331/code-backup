#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    R int n = read(), l = read(), g = read();
    for (R int i = 1; i <= n; ++i)
    {
        R int w = read(), h = read();
        if (w > g || h > g)
        {
            while (w > g || h > g)
                w /= 2, h /= 2;       
        }
        if (w < l || h < l)
        {
            puts("Too Young");
            continue;
        }
        else if (w >= l && h >= l && w != h)
        {
            puts("Too Simple");
            continue;
        }
        else if (w >= l && h >= l && w == h)
        {
            puts("Sometimes Naive");
            continue;
        }
    }
    return 0;
}
