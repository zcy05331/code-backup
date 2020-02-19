#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;
int n, m, p, a[MaxN], ans[MaxN];

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
    n = read(), m = read(), p = read();
    for (R int i = 1; i <= n; ++i)
    {
        int k = read();
        for (R int j = 1; j <= k; ++j)
            ++a[read()];
    }
    int cnt = 0;
    for (R int i = 1; i <= m; ++i)
        if (a[i] == p)
            ans[++cnt] = i;
    printf("%d\n", cnt);
    for (R int i = 1; i <= cnt; i++)
        printf("%d ", ans[i]);
    return 0;
}
