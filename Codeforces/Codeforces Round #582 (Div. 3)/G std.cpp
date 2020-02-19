#include <bits/stdc++.h>
#define gc getchar
#define re register
#define rep(i, s, t) for (re int i = s; i <= t; ++i)
#define reb(i, s, t) for (re int i = s; i >= t; --i)

using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int n, q, fa[N], siz[N];
ll Ans[N], Cur;
struct edge
{
    int u, v, w;
    inline bool operator<(const edge ano) const
    {
        return w < ano.w;
    }
} e[N];
struct Query
{
    int q, id;
    inline bool operator<(const Query ano) const
    {
        return q < ano.q;
    }
} Q[N];

inline int read()
{
    int rt = 0;
    char ch = gc();
    while (ch < '0' || ch > '9')
        ch = gc();
    while (ch >= '0' && ch <= '9')
    {
        rt = (rt << 3) + (rt << 1) + (ch & 15);
        ch = gc();
    }
    return rt;
}
inline void prt(int x)
{
    if (x / 10)
        prt(x / 10);
    putchar(x % 10 + '0');
}
inline int gf(int x) { return fa[x] = x == fa[x] ? x : gf(fa[x]); }
int main()
{
    n = read(), q = read();
    rep(i, 1, n) fa[i] = i, siz[i] = 1;
    rep(i, 1, n - 1) e[i].u = read(), e[i].v = read(), e[i].w = read();
    sort(e + 1, e + n);
    rep(i, 1, q) Q[i].q = read(), Q[i].id = i;
    sort(Q + 1, Q + 1 + q);
    int pos = 0, u, v;
    rep(i, 1, q)
    {
        while (pos < n - 1 && e[pos + 1].w <= Q[i].q)
        {
            ++pos;
            u = gf(e[pos].u), v = gf(e[pos].v);
            if (u == v)
                continue;
            Cur -= 1ll * (siz[u] - 1ll) * siz[u] / 2ll, Cur -= 1ll * (siz[v] - 1ll) * siz[v] / 2ll;
            Cur += 1ll * (siz[u] + siz[v] - 1ll) * (siz[u] + siz[v]) / 2ll;
            siz[u] += siz[v];
            fa[v] = u;
        }
        Ans[Q[i].id] = Cur;
    }
    rep(i, 1, q) printf("%I64d ", Ans[i]);
    return 0;
}