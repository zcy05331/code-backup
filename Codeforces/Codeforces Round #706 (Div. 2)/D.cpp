#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 1e5 + 10;

int n, ans, a[MaxN], l[MaxN], r[MaxN], ls[MaxN], rs[MaxN];
int lp[MaxN], rp[MaxN], linc[MaxN], rinc[MaxN];

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
    n = read(), ans = 0, a[0] = a[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
        a[i] = read(), lp[i] = rp[i] = i;
    for (int i = 2; i <= n; i++)
        if (a[i] < a[i - 1])
            linc[i] = linc[i - 1] + 1;
    for (int i = n - 1; i; i--)
        if (a[i] < a[i + 1])
            rinc[i] = rinc[i + 1] + 1;
    for (int i = 2; i <= n; i++)
        linc[i] = std::max(linc[i], linc[i - 1]);
    for (int i = n - 1; i; i--)
        rinc[i] = std::max(rinc[i], rinc[i + 1]);
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1])
            l[i] = l[i - 1] + 1, lp[i] = lp[i - 1];
    for (int i = n - 1; i; i--)
        if (a[i] > a[i + 1])
            r[i] = r[i + 1] + 1, rp[i] = rp[i + 1];
    for (int i = 1; i <= n; i++)
        ls[i] = std::max(l[i], ls[i - 1]);
    for (int i = n; i; i--)
        rs[i] = std::max(r[i], rs[i + 1]);
    // for(int i = 1; i <= n; i++)
    //     printf("%d %d %d %d\n", linc[i], rinc[i], ls[i], rs[i]);
    for (int i = 1; i <= n; i++)
        if (l[i] && r[i])
        {
            int max = std::max(l[i], r[i]);
            if (ls[i - 1] >= max || rs[i + 1] >= max)
                continue;
            if (linc[i - 1] >= max || rinc[i + 1] >= max)
                continue;
            int min = std::min(l[ i], r[i]);
            if (max & 1) continue;
            if (min & 1) continue;
            if (max > min) continue;
            ++ans; 
        }
    printf("%d\n", ans);
    return 0;
}
