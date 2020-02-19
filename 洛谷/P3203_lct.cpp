#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

int n, m, a[MaxN];

struct LinkCutTree
{
    int fa[MaxN], rev[MaxN], size[MaxN], ch[MaxN][2];
    inline void pushup(int x) { size[x] = size[ch[x][0]] + 1 + size[ch[x][1]]; }
    inline void pushdown(int x)
    {
        if (rev[x])
        {
            rev[ch[x][0]] ^= 1, rev[ch[x][1]] ^= 1;
            rev[x] = 0, std::swap(ch[x][0], ch[x][1]);
        }
    }
    inline int check(int x) { return (ch[fa[x]][1] == x); }
    inline int isroot(int x) { return (ch[fa[x]][0] != x && ch[fa[x]][1] != x); }
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
    inline void cut(int x, int y)
    {
        makeroot(x);
        if (getroot(y) != x || fa[x] != y || ch[x][1])
            return;
        fa[x] = ch[y][0] = 0, pushup(y);
    }
    inline void link(int x, int y) { makeroot(x), fa[x] = y; }
} T;

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
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), T.link(i, ((i + a[i]) <= n) ? (i + a[i]) : (n + 1));
    m = read();
    while (m--)
    {
        int op = read();
        if (op == 1)
        {
            int x = read() + 1;
            T.makeroot(x), T.access(n + 1), T.splay(n + 1), printf("%d\n", T.size[n + 1] - 1);
        }
        else if (op == 2)
        {
            int x = read() + 1, y = read();
            T.cut(x, ((x + a[x]) <= n) ? (x + a[x]) : (n + 1)), a[x] = y, T.link(x, ((x + a[x]) <= n) ? (x + a[x]) : (n + 1));
        }
    }
    return 0;
}
