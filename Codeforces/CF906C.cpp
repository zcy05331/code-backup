#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 22;

std::vector<int> ans;
int n, m, a[MaxN], p[1 << MaxN];
int f[1 << MaxN], fa[1 << MaxN];

void dfs(int x)
{
    if (!x) return;
    ans.push_back(p[x]), dfs(fa[x]);
}

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
    n = read(), m = read();
    if(m == n * (n - 1) / 2)
        return 0 * puts("0");
    for (int i = 1; i <= m; i++)
    {
        int u = read() - 1, v = read() - 1;
        a[u] |= (1 << v), a[v] |= (1 << u);
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; i++)
        a[i] |= (1 << i), f[a[i]] = 1, p[a[i]] = i + 1;
    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
            {
                if (f[i | a[j]] > f[i] + 1)
                    f[i | a[j]] = f[i] + 1, fa[i | a[j]] = i, p[i | a[j]] = j + 1;
            }
    }
    printf("%d\n", f[(1 << n) - 1]), dfs((1 << n) - 1);
    for (auto x : ans) printf("%d ", x);
    return 0;
}
