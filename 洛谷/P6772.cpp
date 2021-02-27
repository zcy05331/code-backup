#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e4 + 10;
const ll inf = -0x3f3f3f3f3f3f3f3f;

struct edge
{
    int next, to, dis;
} e[MaxN << 1];

struct node
{
    int t, x, y;
} v[MaxN];

struct matrix
{
    int n, m;
    ll a[260][260];
    matrix(ll x = 0, ll y = 0)
    {
        n = x, m = y;
        memset(a, -0x3f, sizeof(a));
    }
};

matrix mat[40];
int n, m, t, k, sz, cnt;
int head[MaxN], c[MaxN];

int cmp(node a, node b) { return a.t < b.t; }
int get(int r, int c) { return (r - 1) * n + c; }

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

matrix mul(const matrix &a, const matrix &b)
{
    static matrix c;
    c.n = a.n, c.m = b.m;
    memset(c.a, -0x3f, sizeof(c.a));
    for (int k = 1; k <= a.m; k++)
        for (int i = 1; i <= a.n; i++)
            if (a.a[i][k] != inf)
                for (int j = 1; j <= b.m; j++)
                    c.a[i][j] = std::max(c.a[i][j], a.a[i][k] + b.a[k][j]);
    return c;
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

signed main()
{
    freopen("delicacy.in", "r", stdin);
    freopen("delicacy.out", "w", stdout);
    n = read(), m = read();
    t = read(), k = read(), sz = 5 * n;
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(v, u, d);
    }
    for(int i = 0; i <= 30; i++)
        mat[i] = matrix(sz, sz);
    for (int i = 1; i <= k; i++)
        v[i].t = read(), v[i].x = read(), v[i].y = read();
    std::sort(v + 1, v + k + 1, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = head[i]; j; j = e[j].next)
            mat[0].a[get(e[j].dis, e[j].to)][i] = c[i];
    for (int i = 1; i + n <= sz; i++)
        mat[0].a[i][i + n] = 0;
    for (int i = 1; i <= 30; i++)
        mat[i] = mul(mat[i - 1], mat[i - 1]);
    static matrix ans(1, sz); ans.a[1][1] = c[1];
    for (int i = 1; i <= k; i++)
    {
        for(int j = 30; ~j; j--)
            if((v[i].t - v[i - 1].t) & (1 << j))
                ans = mul(ans, mat[j]);
        ans.a[1][v[i].x] += v[i].y;
    }
    for (int j = 30; ~j; j--)
        if ((t - v[k].t) & (1 << j))
            ans = mul(ans, mat[j]);
    printf("%lld\n", (ans.a[1][1] < 0) ? -1 : ans.a[1][1]);
    return 0;
}