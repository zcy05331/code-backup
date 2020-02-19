#include <cstdio>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define For(i, x) for (int i = h[x], k; i; i = nxt[i])
using namespace std;

const int N = 1000010, inf = 1e9;
char s[N];
int n, cnt, d[N], fa[N], ans[N], w[N], sz[N], son[N], p[1 << 23], h[N], to[N << 1], nxt[N << 1];
void add(int u, int v)
{
    to[++cnt] = v;
    nxt[cnt] = h[u];
    h[u] = cnt;
}

void dfs(int x)
{
    d[x] = d[fa[x]] + 1;
    sz[x] = 1;
    For(i, x)
    {
        k = to[i];
        w[k] = w[x] ^ (1 << (s[k] - 'a'));
        dfs(k);
        sz[x] += sz[k];
        if (sz[k] > sz[son[x]])
            son[x] = k;
    }
}

void get(int rt, int x)
{
    ans[rt] = max(ans[rt], p[w[x]] + d[x] - 2 * d[rt]);
    rep(i, 0, 21) ans[rt] = max(ans[rt], p[w[x] ^ (1 << i)] + d[x] - 2 * d[rt]), printf("%d ", ans[rt]);

    For(i, x) get(rt, k = to[i]);
}

void get2(int x)
{
    p[w[x]] = max(p[w[x]], d[x]);
    For(i, x) get2(k = to[i]);
}

void del(int x)
{
    p[w[x]] = -inf;
    For(i, x) del(k = to[i]);
}

void work(int x, int op)
{
    For(i, x) if ((k = to[i]) != son[x]) work(k, 1),
        ans[x] = max(ans[x], ans[k]);
    if (son[x])
        work(son[x], 0), ans[x] = max(ans[x], ans[son[x]]);
    For(i, x) if ((k = to[i]) != son[x]) get(x, k), get2(k);
    ans[x] = max(ans[x], p[w[x]] - d[x]);
    rep(i, 0, 21) ans[x] = max(ans[x], p[w[x] ^ (1 << i)] - d[x]);
    p[w[x]] = max(p[w[x]], d[x]);
    if (op)
        del(x);
}

int main()
{
    // freopen("741D.in", "r", stdin);
    // freopen("741D.out", "w", stdout);
    scanf("%d", &n);
    rep(i, 2, n) scanf("%d %c", &fa[i], &s[i]), add(fa[i], i);
    rep(i, 0, (1 << 22) - 1) p[i] = -inf;
    dfs(1);
    work(1, 0);
    rep(i, 1, n) printf("%d ", ans[i]);
    return 0;
}
