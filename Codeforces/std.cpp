//It is made by M_sea
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#define re register
#define mp make_pair
typedef int mainint;
#define int long long
using namespace std;

inline int read()
{
    int X = 0, w = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        X = X * 10 + c - '0', c = getchar();
    return X * w;
}

const int MAXN = 100000 + 10;

int n, m;
struct Edge
{
    int v, w, nxt;
};
Edge e[MAXN << 1];
int head[MAXN], cnt = 0;

inline void addEdge(int u, int v, int w)
{
    e[++cnt].v = v, e[cnt].w = w, e[cnt].nxt = head[u], head[u] = cnt;
}

int vis[MAXN];
int p[MAXN]; //p[i]=10^i
int sz[MAXN], f[MAXN], dep[MAXN];
int root, sum, ans, num;
map<int, int> s;               //sum[d1]为d1的数量
pair<int, int> dig[MAXN << 1]; //<d2,dep>

inline void getroot(int u, int fa)
{
    sz[u] = 1, f[u] = 0;
    for (re int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v] || v == fa) continue;
        getroot(v, u);
        sz[u] += sz[v];
        f[u] = max(f[u], sz[v]);
    }
    f[u] = max(f[u], sum - f[u]);
    if (f[u] < f[root]) root = u;
}

inline void getdigit(int u, int fa, int d1, int d2, int d)
{
    if (d >= 0) ++s[d1], dig[++num] = mp(d2, d);
    for (re int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v, w = e[i].w;
        if (v == fa || vis[v]) continue;
        int d3 = (d1 + w * p[d + 1]) % m;
        int d4 = (d2 * 10 + w) % m;
        getdigit(v, u, d3, d4, d + 1);
    }
}

inline int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int z = x;
    x = y;
    y = z - a / b * y;
    return d;
}
inline int inv(int a, int m)
{ //a在mod m意义下的逆元
    int x, y, d = exgcd(a, m, x, y);
    return d == 1 ? (x % m + m) % m : -1;
}

inline int calc(int u, int d)
{
    s.clear();
    int rt = 0;
    num = 0;
    if (d)
        getdigit(u, 0, d % m, d % m, 0);
    else
        getdigit(u, 0, 0, 0, -1);
    for (re int i = 1; i <= num; ++i)
    {
        int tmp = (-dig[i].first * inv(p[dig[i].second + 1], m) % m + m) % m;
        if (s.find(tmp) != s.end()) rt += s[tmp];
        if (!d) rt += !dig[i].first;
    }
    if (!d) rt += s[0]; //0也能被m整除
    printf("$ %lld %lld %lld\n", u, rt, dig);
    return rt;
}

inline void solve(int u)
{
    ans += calc(u, 0);
    vis[u] = 1;
    for (re int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v, w = e[i].w;
        if (vis[v]) continue;
        ans -= calc(v, w);
        sum = sz[v], f[0] = n, root = 0;
        getroot(v, u);
        solve(root);
    }
}

mainint main()
{
    n = read(), m = read();
    for (re int i = 1, u, v, w; i < n; ++i)
    {
        u = read() + 1, v = read() + 1, w = read();
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    p[0] = 1;
    for (re int i = 1; i <= n; ++i)
        p[i] = p[i - 1] * 10 % m;
    f[0] = sum = n;
    getroot(1, 0);
    solve(root);
    printf("%lld\n", ans);
    return 0;
}