#include <bits/stdc++.h>

#define R register
#define ll long long
#define pair std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct LinkCutTree
{
    int fa[MaxN], sum[MaxN], val[MaxN];
    int mul[MaxN], siz[MaxN], rev[MaxN], ch[MaxN][2];
    inline void pushup(int x)
    {
        siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
        sum[x] = sum[ch[x][0]] + val[x] + sum[ch[x][1]];
    }
    inline void pushmul(int x) { val[x] = 0, mul[x] = 0, sum[x] = 0; }
    inline void pushdown(int x)
    {
        int lc = ch[x][0], rc = ch[x][1];
        if (!mul[x])
            pushmul(lc), pushmul(rc), mul[x] = 1;
        if (rev[x])
        {
            rev[lc] ^= 1, rev[rc] ^= 1;
            rev[x] = 0, std::swap(ch[x][0], ch[x][1]);
        }
    }
    inline int check(int x) { return ch[fa[x]][1] == x; }
    inline int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    inline void rotate(int x)
    {
        int f = fa[x], gf = fa[f], tp = check(x);
        (!isroot(f)) ? (ch[gf][check(f)] = x) : 0;
        fa[ch[x][tp ^ 1]] = f, fa[f] = x, fa[x] = gf;
        ch[f][tp] = ch[x][tp ^ 1], ch[x][tp ^ 1] = f, pushup(f), pushup(x);
    }
    inline void update(int x)
    {
        if (!isroot(x))
            update(fa[x]);
        pushdown(x);
    }
    inline void splay(int x)
    {
        update(x);
        for (int y = 0; y = fa[x], !isroot(x); rotate(x))
            if (!isroot(y))
                rotate((check(x) ^ check(y)) ? x : y);
    }
    inline void access(int x)
    {
        for (int y = 0; x; y = x, x = fa[x])
            splay(x), ch[x][1] = y, pushup(x);
    }
    inline void makeroot(int x) { access(x), splay(x), rev[x] = 1; }
    inline int getroot(int x)
    {
        access(x), splay(x);
        while (ch[x][0])
            x = ch[x][0];
        return x;
    }
    inline void split(int x, int y) { makeroot(x), access(y), splay(y); }
    inline void link(int x, int y) { makeroot(x), fa[x] = y; }
} T;

struct query
{
    char op;
    int x, y;
} Q[MaxN];

std::map<pair, int> g;
int n, m, q, now, u[MaxN], v[MaxN], f[MaxN], ans[MaxN];

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

char get()
{
    char c = getchar();
    while (!isalpha(c))
        c = getchar();
    return c;
}

inline int cmp(pair x, pair y)
{
    if (g[mp(x.first, x.second)] != g[mp(y.first, y.second)])
        return g[mp(x.first, x.second)] < g[mp(y.first, y.second)];
    return x.first < y.first;
}

void link(int x, int y)
{
    f[getf(x)] = getf(y), T.val[++now] = 1;
    T.link(x, now), T.link(now, y);
};

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
    n = read(), m = read(), q = read(), now = n;
    for (int i = 1; i <= n; i++)
        T.val[i] = T.mul[i] = 1, f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        u[i] = read(), v[i] = read();
        if (u[i] > v[i]) std::swap(u[i], v[i]);
        g[mp(u[i], v[i])] = 0;
    }
    for (int i = 1; i <= q; i++)
    {
        Q[i].op = get(), Q[i].x = read(), Q[i].y = read();
        if (Q[i].x > Q[i].y) std::swap(Q[i].x, Q[i].y);
        if (Q[i].op == 'Z') g[mp(Q[i].x, Q[i].y)] = i;
    }
    for (int i = 1; i <= m; i++)
        if (g[mp(u[i], v[i])] == 0)
        {
            int fu = getf(u[i]), fv = getf(v[i]);
            if (fu != fv)
                link(u[i], v[i]);
            else
                T.split(u[i], v[i]), T.pushmul(v[i]);
        }
    for (int i = q; i; i--)
    {
         int fu = getf(Q[i].x), fv = getf(Q[i].y);
        if (Q[i].op == 'Z')
        {
            if (fu != fv)
                link(Q[i].x, Q[i].y);
            else
                T.split(Q[i].x, Q[i].y), T.pushmul(Q[i].y);
        }
        else
        {   
            T.split(Q[i].x, Q[i].y), ans[i] = !T.sum[Q[i].y];
            if(fu != fv) ans[i] = 0;
        }
    }
    for (int i = 1; i <= q; i++)
        if (Q[i].op == 'P')
            puts(ans[i] ? "TAK" : "NIE");
    return 0;
}