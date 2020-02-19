#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

struct edge
{
    int from, to, dis, id;
};

edge e[MaxN << 1];
int n, m, q;
int ok[MaxN], f[MaxN];

int cmp(edge a, edge b) { return a.dis < b.dis; }

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

inline void merge(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    if (fu != fv)
        f[fu] = fv;
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

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
        e[i].from = read(), e[i].to = read(), e[i].dis = read(), e[i].id = i;
    int l = 1;
    std::sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (e[i].dis != e[i - 1].dis)
            l = i;
        if (e[i].dis != e[i + 1].dis)
        {
            for (int j = l; j <= i; j++)
            {
                int u = e[j].from, v = e[j].to;
                if (getf(u) != getf(v))
                    ok[e[j].id] = 1;
            }
            for (int j = l; j <= i; j++)
                if (ok[e[j].id])
                    merge(e[j].from, e[j].to);
        }
    }
    q = read();
    while (q--)
    {
        int x = read();
        printf(ok[x] ? "YE5\n" : "N0\n");
    }
    return 0;
}
