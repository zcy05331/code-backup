#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int MaxT = 2e3 + 10;
const int MaxM = 2e5 + 10;

std::queue<int> v1[MaxT];
std::vector<int> v[MaxT];
std::deque<int> que[MaxN + 30000];
ll n, m, A, B, C, tim, ans = 1e17;
ll f[MaxN], x[MaxM], y[MaxM], p[MaxM], q[MaxM];

ll X(ll num) { return q[num]; }
ll K(ll num) { return 2 * A * p[num]; }
ll g(ll x) { return A * x * x + B * x + C; }
ll Y(ll num) { return f[num] + A * q[num] * q[num] - B * q[num]; }
double slope(int a, int b) {return (1.0 * (Y(a) - Y(b))) / (1.0 * (X(a) - X(b))); }

void insert(int id)
{
    int pos = y[id];
#define r que[pos].size()
    while (r >= 2)
    {
        if (slope(que[pos][r - 1], que[pos][r - 2]) < slope(id, que[pos][r - 1]))
            break;
        else
            que[pos].pop_back();
    }
#undef r
    que[pos].push_back(id);
}

void pop(int pos, double s)
{
    while (que[pos].size() >= 2)
    {
        if (s < slope(que[pos][1], que[pos][0])) break;
        que[pos].pop_front();
    }
}

inline ll read()
{
    ll x = 0;
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
    A = read(), B = read(), C = read();
    for (int i = 1; i <= m; i++)
    {
        x[i] = read(), y[i] = read();
        p[i] = read(), q[i] = read(), tim = std::max(tim, q[i]);
    }
    for (int i = 1; i <= m; i++)
        v[p[i]].push_back(i);
    que[1].push_back(0);
    for (int i = 0; i <= tim; i++)
    {
        while (!v1[i].empty())
            insert(v1[i].front()), v1[i].pop();
        int l = v[i].size();
        for (int o = 0; o < l; o++)
        {
            int id = v[i][o], pos = x[id];
            if (!que[pos].size()) continue;
            pop(pos, K(id));
            int j = que[pos].front();
            f[id] = f[j] + g(p[id] - q[j]), v1[q[id]].push(id);
            if (y[id] == n) ans = std::min(ans, q[id] + f[id]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
