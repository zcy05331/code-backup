#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int a, b, k;

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
    a = read(), b = read(), k = read();
    if (k == 0)
    {
        puts("Yes");
        for (int i = 1; i <= b; i++)
            putchar('1');
        for (int i = 1; i <= a; i++)
            putchar('0');
        puts("");
        for (int i = 1; i <= b; i++)
            putchar('1');
        for (int i = 1; i <= a; i++)
            putchar('0');
        return 0;
    }
    if (k > a + 1) return 0 * puts("No");
    if (b == 1 && k > 0) return 0 * puts("No");
    if (k <= a)
    {
        puts("Yes");
        for (int i = 1; i <= b; i++)
            putchar('1');
        for (int i = 1; i <= a; i++)
            putchar('0');
        puts("");
        for (int i = 1; i <= b - 1; i++)
            putchar('1');
        for (int i = 1; i <= k; i++)
            putchar('0');
        putchar('1');
        for (int i = k + 1; i <= a; i++)
            putchar('0');
        return 0;
    }
    else if(a != b)
    {
        puts("Yes");
        for (int i = 1; i <= b; i++)
            putchar('1');
        for (int i = 1; i <= a; i++)
            putchar('0');
        puts(""), putchar('1');
        for (int i = 1; i <= a; i++)
            putchar('0');
        for (int i = 1; i <= b - 1; i++)
            putchar('1');
        return 0;
    }
    else puts("No");
    return 0;
}
