#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;
const int mod = 998244353;

struct edge
{
    int next, to;
};

struct mod_t
{
    static int norm(int x) { return x + (x >> 31 & mod); }
    int x;
    mod_t() {}
    mod_t(int v) : x(v) {}
    mod_t(long long v) : x(v) {}
    mod_t(char v) : x(v) {}
    mod_t operator+(const mod_t &rhs) const { return norm(x + rhs.x - mod); }
    mod_t operator-(const mod_t &rhs) const { return norm(x - rhs.x); }
    mod_t operator*(const mod_t &rhs) const { return (ll)x * rhs.x % mod; }
};

edge e[MaxN << 1];
std::vector<int> up[MaxN], down[MaxN];

char s[MaxN];
int n, m, cnt;
mod_t base, inv, h[MaxN], revh[MaxN], powm[MaxN], invp[MaxN];
int head[MaxN], dep[MaxN], maxd[MaxN], fir[MaxN], lg2[MaxN], top[MaxN];
int son[MaxN], fa[MaxN][24], f[MaxN][24], Dep[MaxN << 4], pos[MaxN << 4];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int querykth(int u, int k)
{
    if (!k) return u;
    u = fa[u][lg2[k]], k -= (1 << lg2[k]);
    k -= (dep[u] - dep[top[u]]), u = top[u];
    return ((k >= 0) ? up[u][k] : down[u][-k]);
}

int querylca(int u, int v)
{
    int l = fir[u], r = fir[v], k;
    if (l > r) std::swap(l, r);
    k = lg2[r - l + 1];
    return ((Dep[f[l][k]] <= Dep[f[r - (1 << k) + 1][k]]) ? pos[f[l][k]] : pos[f[r - (1 << k) + 1][k]]);
}

// int querylca(int u, int v)
// {
//     if (dep[u] < dep[v])
//         std::swap(u, v);
//     u = querykth(u, dep[u] - dep[v]);
//     if(u == v) return u;
//     for(int i = 20; ~i; i--)
//         if(fa[u][i] != fa[v][i])
//             u = fa[u][i], v = fa[v][i];
//     return fa[u][0];
// }

mod_t fast_pow(mod_t a, ll b)
{
    mod_t ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ret * a);
        a = (a *  a), b >>= 1;
    }
    return ret;
}

void init()
{
    powm[0] = invp[0] = 1, base = 100;
    inv = fast_pow(base, mod - 2);
    for (int i = 1; i <= n; i++)
    {
        powm[i] = (powm[i - 1] * 1ll * base);
        invp[i] = (invp[i - 1] * 1ll * inv);
    }
}

void prework()
{
    lg2[0] = -1;
    for (int i = 1; i <= cnt; i++)
        lg2[i] = lg2[i >> 1] + 1, f[i][0] = i;
    for (int j = 1; (1 << j) <= cnt; j++)
    {
        for (int i = 1; i <= cnt - (1 << j) + 1; i++)
            f[i][j] = ((Dep[f[i][j - 1]] <= Dep[f[i + (1 << (j - 1))][j - 1]]) ? f[i][j - 1] : f[i + (1 << (j - 1))][j - 1]);
    }
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch - 48), ch = getchar();
    return x;
}

void dfs(int u, int fa)
{
    Dep[++cnt] = maxd[u] = dep[u] = dep[fa] + 1, ::fa[u][0] = fa;
    pos[cnt] = u, h[u] = (h[fa] * base + (s[u] - 'a'));
    fir[u] = cnt, revh[u] = (revh[fa] + powm[dep[u] - 1] * 1ll * (s[u] - 'a'));
    // printf("debug: %d %lld %lld\n", u, h[u], revh[u]);
    for (int i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u), pos[++cnt] = u, Dep[cnt] = dep[u];
        if (maxd[v] > maxd[u])
            maxd[u] = maxd[v], son[u] = v;
    }
}

void dfs1(int u, int top)
{
    ::top[u] = top;
    if (u == top)
    {
        int x = u;
        for (int i = 0; i <= maxd[u] - dep[u]; i++)
            up[u].push_back(x), x = fa[x][0];
        x = u;
        for (int i = 0; i <= maxd[u] - dep[u]; i++)
            down[u].push_back(x), x = son[x];
    }
    if (son[u]) dfs1(son[u], top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != son[u] && v != fa[u][0]) dfs1(v, v);
    }
}

int qhash(int u, int v, int lca, int flca)
{
    mod_t h1 = (h[u] - powm[dep[u] - dep[lca]] * h[lca]);
    mod_t h2 = (revh[v] - revh[flca] + mod) * invp[dep[lca] - 1];
    return (h1 + h2 * powm[dep[u] - dep[lca]]).x;
}

int get(int u, int v, int k)
{
    int lca = querylca(u, v), v1;
    int d = dep[u] + dep[v] - 2 * dep[lca] + 1;
    if (k <= dep[u] - dep[lca])
    {
        v1 = querykth(u, k - 1);
        return qhash(u, v1, v1, fa[v1][0]);
    }
    else
    {
        v1 = querykth(v, d - k);
        return qhash(u, v1, lca, fa[lca][0]);
    }
}

int query(int a, int b, int c, int d)
{
    if (s[a] != s[c]) return 0;
    int lca1 = querylca(a, b), d1 = dep[a] + dep[b] - 2 * dep[lca1] + 1;
    int lca2 = querylca(c, d), d2 = dep[c] + dep[d] - 2 * dep[lca2] + 1;
    int l = 1, r = std::min(d1, d2);
    // printf("debug: a = %d, b = %d, c = %d, d = %d, lca(a, b) = %d, lca(c, d) = %d\n", a, b, c, d, lca1, lca2);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        // printf("Debug: l = %d, r = %d, mid = %d, v1 = %d, v2 = %d, h1 = %d, h2 = %d\n", l, r, mid, v1, v2, qhash(a, v1), qhash(c, v2));
        if (get(a, b, mid) == get(c, d, mid))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    scanf("%d\n%s", &n, s + 1), init();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    m = read(), cnt = 0, dfs(1, 0), dfs1(1, 1), prework();
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), c = read(), d = read();
        printf("%d\n", query(a, b, c, d));
    }
    return 0;
}