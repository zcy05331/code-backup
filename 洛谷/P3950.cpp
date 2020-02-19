#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;
int n, m, cnt, u[MaxN], v[MaxN];
struct LinkCutTree
{
    int ch[MaxN][2], fa[MaxN], rev[MaxN];
    inline void pushdown(int x)
    {
        if (rev[x])
        {
            rev[ch[x][0]] ^= 1, rev[ch[x][1]] ^= 1;
            rev[x] = 0, std::swap(ch[x][0], ch[x][1]);
        }
    }
    int check(int x) { return (ch[fa[x]][1] == x); }
    int isroot(int x) { return (ch[fa[x]][0] != x && ch[fa[x]][1] != x); }
    inline void rotate(int x)
    {
        int f = fa[x], gf = fa[f], tp = check(x);
        if (!isroot(f))
            ch[gf][check(f)] = x;
        fa[ch[x][tp ^ 1]] = f, fa[x] = gf, fa[f] = x;
        ch[f][tp] = ch[x][tp ^ 1], ch[x][tp ^ 1] = f;
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
            splay(x), ch[x][1] = y;
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
        fa[x] = ch[y][0] = 0;
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
    n = read(), m = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        T.link(u, v);
    }
    char ch[2];
    while (m--)
    {
        scanf("%s", ch + 1);
        if (ch[1] == 'Q')
        {
            int x = read(), y = read(), fx = T.getroot(x), fy = T.getroot(y);
            printf((fx == fy) ? "Yes\n" : "No\n");
        }
        else if (ch[1] == 'C')
            ++cnt, u[cnt] = read(), v[cnt] = read(), T.cut(u[cnt], v[cnt]);
        else if (ch[1] == 'U')
        {
            int x = read();
            T.link(u[x], v[x]);
        }
    }
    return 0;
}
