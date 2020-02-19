#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson rt << 1
#define rson rt << 1 | 1
inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
template <class Tp>
inline void read(register Tp &s)
{
    s = 0;
    register bool neg = 0;
    register char c = nc();
    for (; c < '0' || c > '9'; c = nc())
        neg |= (c == '-');
    for (; c >= '0' && c <= '9'; s = s * 10 + (c ^ 48), c = nc())
        ;
    s = (neg ? -s : s);
}

const int N = 1e5 + 5, M = 2e5 + 5;
int n, idx, dfn[N], seq[N], U[N], V[N], W[N], val[N], fa[N], dep[N], top[N], sz[N], hvy[N];
int tot, lnk[N], ter[M], nxt[M], wei[M], seg[N << 2];

void add(int u, int v, int w)
{
    ter[++tot] = v, wei[tot] = w, nxt[tot] = lnk[u], lnk[u] = tot;
}
void dfs1(int u, int f)
{
    fa[u] = f, dep[u] = dep[f] + 1, sz[u] = 1, hvy[u] = top[u] = 0;
    for (int i = lnk[u]; i; i = nxt[i])
    {
        int v = ter[i];
        if (v == f)
            continue;
        val[v] = wei[i];
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[hvy[u]] < sz[v])
            hvy[u] = v;
    }
}
void dfs2(int u, int tp)
{
    dfn[u] = ++idx, seq[idx] = u, top[u] = tp;
    if (!hvy[u])
        return;
    dfs2(hvy[u], tp);
    for (int i = lnk[u]; i; i = nxt[i])
    {
        int v = ter[i];
        if (v == fa[u] || v == hvy[u])
            continue;
        dfs2(v, v);
    }
}
void pushup(int rt)
{
    seg[rt] = std::max(seg[lson], seg[rson]);
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        seg[rt] = val[seq[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void modify(int x, int rt, int l, int r, int val)
{
    if (l == r)
    {
        seg[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        modify(x, lson, l, mid, val);
    else
        modify(x, rson, mid + 1, r, val);
    pushup(rt);
}
int query(int x, int y, int rt, int l, int r)
{
    if (x > y)
        return 0;
    if (x <= l && r <= y)
        return seg[rt];
    int mid = (l + r) >> 1, res = 0;
    if (x <= mid)
        res = std::max(res, query(x, y, lson, l, mid));
    if (mid < y)
        res = std::max(res, query(x, y, rson, mid + 1, r));
    return res;
}
int chainQuery(int u, int v)
{
    if (u == v)
        return 0;
    int res = 0;
    for (int fu = top[u], fv = top[v]; fu ^ fv; u = fa[fu], fu = top[u])
    {
        if (dep[fu] < dep[fv])
            std::swap(u, v), std::swap(fu, fv);
        res = std::max(res, query(dfn[fu], dfn[u], 1, 1, n));
    }
    if (dep[u] > dep[v])
        std::swap(u, v);
    res = std::max(res, query(dfn[u] + 1, dfn[v], 1, 1, n));
    return res;
}
int main()
{
    int T;
    for (read(T); T--;)
    {
        read(n);
        idx = tot = 0, memset(lnk, 0, sizeof(lnk));
        for (int i = 1; i < n; ++i)
        {
            int u, v, w;
            read(u), read(v), read(w);
            add(u, v, w), add(v, u, w);
            U[i] = u, V[i] = v, W[i] = w;
        }
        dfs1(1, 0), dfs2(1, 1), build(1, 1, n);
        while (1)
        {
            char c = nc();
            while (c < 'A' || c > 'Z')
                c = nc();
            if (c == 'D')
                break;
            int x, y;
            read(x), read(y);
            if (c == 'C')
            {
                int u = U[x], v = V[x];
                if (fa[v] == u)
                    std::swap(u, v);
                modify(dfn[u], 1, 1, n, y);
            }
            else
            {
                printf("%d\n", chainQuery(x, y));
            }
        }
    }
    return 0;
}