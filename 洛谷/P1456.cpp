#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct node
{
    int ch[2];
    int val, dep;
};

node t[MaxN];
int n, m, f[MaxN];

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

int merge(int x, int y)
{
    if (!x || !y) return x | y;
    if (t[x].val < t[y].val) std::swap(x, y);
    t[x].ch[1] = merge(t[x].ch[1], y);
    if (t[t[x].ch[1]].dep > t[t[x].ch[0]].dep)
        std::swap(t[x].ch[0], t[x].ch[1]);
    t[x].dep = t[t[x].ch[1]].dep + 1;
    return x;
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

int solve(int a, int b)
{
    a = getf(a), b = getf(b);
    if (a == b) return -1;
    int rt, art, brt;
    t[a].val >>= 1, rt = merge(t[a].ch[0], t[a].ch[1]);
    t[a].ch[0] = t[a].ch[1] = t[a].dep = 0, art = merge(rt, a), f[a] = f[rt] = art;
    t[b].val >>= 1, rt = merge(t[b].ch[0], t[b].ch[1]);
    t[b].ch[0] = t[b].ch[1] = t[b].dep = 0, brt = merge(rt, b), f[b] = f[rt] = brt;
    rt = merge(art, brt), f[art] = f[brt] = rt;
    return t[rt].val;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        t[0].dep = -1;
        for (int i = 1; i <= n; i++)
        {
            t[i].val = read(), f[i] = i;
            t[i].dep = t[i].ch[0] = t[i].ch[1] = 0;
        }
        m = read();
        while (m--)
        {
            int a = read(), b = read();
            printf("%d\n", solve(a, b));
        }
    }
    return 0;
}
