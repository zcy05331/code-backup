#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxP = 1e2 + 10;
const ll MaxN = 1e5 + 10;

ll n, m, p;
ll d[MaxN], h[MaxN], t[MaxN], l[MaxN], r[MaxN];
ll a[MaxN], q[2][MaxN], s[MaxN], f[2][MaxN];

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

ll X(ll p, ll num){return num;}
ll K(ll p, ll num){return a[num];}
ll Y(ll p, ll num){return f[p & 1][num] + s[num];}

signed main()
{
    n = read(), m = read(), p = read();
    if (p >= m)
        return 0 * puts("0");
    for (ll i = 2; i <= n; i++)
        d[i] = read() + d[i - 1];
    for (ll i = 1; i <= m; i++)
        h[i] = read(), t[i] = read(), a[i] = t[i] - d[h[i]];
    std::sort(a + 1, a + m + 1);
    for (ll i = 1; i <= m; i++)
        s[i] = s[i - 1] + a[i];
    for (ll i = 1; i <= p; i++)
    {
        ll pre = (i - 1) & 1, cur = i & 1;
        q[cur][l[i] = r[i] = 1] = 0;
        for (ll j = 1; j <= m; j++)
        {
            while (l[i - 1] < r[i - 1] && (Y(i - 1, q[pre][l[i - 1] + 1]) - Y(i - 1, q[pre][l[i - 1]])) <= K(i, j) * (X(i - 1, q[pre][l[i - 1] + 1]) - X(i - 1, q[pre][l[i - 1]])))
                l[i - 1]++;
            f[cur][j] = f[pre][q[pre][l[i - 1]]] + a[j] * (j - q[pre][l[i - 1]]) - (s[j] - s[q[pre][l[i - 1]]]);
            while (l[i] < r[i] && (Y(i, q[cur][r[i]]) - Y(i, q[cur][r[i] - 1])) * (X(i, j) - X(i, q[cur][r[i]])) > (Y(i, j) - Y(i, q[cur][r[i]])) * (X(i, q[cur][r[i]]) - X(i, q[cur][r[i] - 1])))
                r[i]--;
            q[cur][++r[i]] = j;
        }
    }
    printf("%lld\n", f[p & 1][m]);
    return 0;
}
