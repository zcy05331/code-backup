#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

int n, m, k;
int ans[MaxN], a[MaxN][MaxN], s[MaxN][MaxN];

inline int read()
{
    R int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read(), m = read(), k = read();
    for (R int i = 1; i <= n; ++i)
        for (R int j = 1; j <= m; ++j)
            a[i][j] = read(), ans[a[i][j]] += (1 - s[a[i][j]][j]), s[a[i][j]][j] = 1;
    for (R int i = 1; i <= k; ++i)
        printf("%d ", ans[i]);
    return 0;
}
