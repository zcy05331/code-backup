#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

int n, a[MaxN], pre[MaxN], ans[MaxN], max[MaxN];

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
        n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read(), pre[i] = 0;
            ans[i] = MaxN, max[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            max[a[i]] = std::max(max[a[i]], i - pre[a[i]]);
            pre[a[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            max[a[i]] = std::max(max[a[i]], n + 1 - pre[a[i]]);
            ans[max[a[i]]] = std::min(ans[max[a[i]]], a[i]);
        }
        for (int i = 2; i <= n; i++)
            ans[i] = std::min(ans[i], ans[i - 1]);
        for (int i = 1; i <= n; i++)
            printf("%d%c", ((ans[i] == MaxN) ? -1 : ans[i]), " \n"[i == n]);
    }
    return 0;
}
