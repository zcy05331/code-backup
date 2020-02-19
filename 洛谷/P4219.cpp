#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, q;
struct LinkCutTree
{
    int fa[MaxN], ch[MaxN][2], siz[MaxN], size[MaxN], rev[MaxN];
    inline void pushup(int x) { size[x] = 1 + size[ch[x][0]] + siz[x] + size[ch[x][1]]; }
    inline void pushdown(int x)
    {
        if (rev[x])
        {
            rev[ch[x][0]] ^= 1, rev[ch[x][1]] ^= 1;
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
        {
            splay(x), siz[x] += size[ch[x][1]];
            ch[x][1] = y, siz[x] -= size[ch[x][1]], pushup(x);
        }
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
    inline void link(int x, int y) { split(x, y), fa[x] = y, siz[y] += size[x], pushup(x); }
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
    char ch[2];
    n = read(), q = read();
    for (int i = 1; i <= n; ++i)
        T.size[i] = 1;
    while (q--)
    {
        scanf("%s", ch + 1);
        int x = read(), y = read();
        if (ch[1] == 'A')
            T.link(x, y);
        else
        {
            T.split(x, y);
            printf("%lld\n", (T.siz[x] + 1) * 1ll * (T.siz[y] + 1));
        }
    }
    return 0;
}
