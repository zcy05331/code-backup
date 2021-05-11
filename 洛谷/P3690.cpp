#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 3e5 + 10;

int n, m, val[MaxN];

struct LinkCutTree
{
    int root, ch[MaxN][2], fa[MaxN], rev[MaxN], sum[MaxN];
    void pushup(int x) { sum[x] = sum[ch[x][0]] ^ val[x] ^ sum[ch[x][1]]; }
    void pushdown(int x)
    {
        int &lc = ch[x][0], &rc = ch[x][1];
        if(rev[x]) rev[x] ^= 1, rev[lc] ^= 1, rev[rc] ^= 1, std::swap(lc, rc);
    }
    int check(int x) { return ch[fa[x]][1] == x; }
    int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    void rotate(int x)
    {
        int f = fa[x], gf = fa[f], tp = check(x);
        if(!isroot(f)) ch[gf][check(f)] = x;
        fa[ch[x][tp ^ 1]] = f, fa[x] = gf, fa[f] = x;
        ch[f][tp] = ch[x][tp ^ 1], ch[x][tp ^ 1] = f, pushup(f), pushup(x);
    }
    void update(int x)
    {
        if(!isroot(x)) 
            update(fa[x]);
        pushdown(x);
    }
    inline void splay(int x)
    {
        update(x);
        for(int f = 0; f = fa[x], !isroot(x); rotate(x))
            if(!isroot(f)) rotate((check(x) ^ check(f)) ? x : f);
    }
    inline void access(int x)
    {
        for(int y = 0; x; y = x, x = fa[x])
            splay(x), ch[x][1] = y, pushup(x);
    }
    inline void makeroot(int x) { access(x), splay(x), rev[x] = 1; }
    int getroot(int x)
    {
        access(x), splay(x);
        while(ch[x][0])
            x = ch[x][0];
        return x;
    }
    void split(int x, int y) { makeroot(x), access(y), splay(y); }
    void cut(int x, int y)
    {
        makeroot(x);
        if(getroot(y) != x || fa[x] != y || ch[x][1])
            return;
        fa[x] = ch[y][0] = 0, pushup(y);
    }
    void link(int x, int y) { makeroot(x), fa[x] = y; }
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
    for (int i = 1; i <= n; i++)
        val[i] = T.sum[i] = read();
    while (m--)
    {
        int op = read(), x = read(), y = read();
        if (op == 0)
            T.split(x, y), printf("%d\n", T.sum[y]);
        else if (op == 1)
        {
            int fx = T.getroot(x), fy = T.getroot(y);
            (fx != fy) ? T.link(x, y) : (void)1;
        }
        else if (op == 2)
        {
            int fx = T.getroot(x), fy = T.getroot(y);
            (fx == fy) ? T.cut(x, y) : (void)1;
        }
        else
            T.access(x), T.splay(x), val[x] = y, T.pushup(x);
    }
    return 0;
}