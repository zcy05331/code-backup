#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, sum, a[MaxN];

int lowbit(int x) 
{ 
    int z = 0;
    while(x & 1)
        x >>= 1, z++;
    return z;
}

int f(int x, int y) { return lowbit((x - 1) | (y - 1)); }

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

signed main()
{
    int T = read();
    while (T--)
    {
        n = read(), sum = 0;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i += 2)
            sum ^= f(a[i], a[i + 1]);
        puts(sum ? "YES" : "NO");
    }
    return 0;
}
