#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 1e5 + 10;

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

std::vector<ll> st[MaxN];
ll n, a[MaxN], last[MaxN], cnt[MaxN], f[MaxN];

ll X(ll num) { return cnt[num]; }
ll K(ll num) { return 2 * a[num] * cnt[num]; }
ll Y(ll num) { return f[num - 1] + a[num] * cnt[num] * cnt[num] - 2 * a[num] * cnt[num]; }

int main()
{
    n = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read(), cnt[i] = cnt[last[a[i]]] + 1, last[a[i]] = i;
    for (ll i = 1; i <= n; i++)
    {
        while (st[a[i]].size() >= 2 && (Y(i) - Y(st[a[i]].back())) * (X(st[a[i]].back()) - X(st[a[i]][st[a[i]].size() - 2])) >= (Y(st[a[i]].back()) - Y(st[a[i]][st[a[i]].size() - 2])) * (X(i) - X(st[a[i]].back())))
            st[a[i]].pop_back();
        st[a[i]].push_back(i);
        while (st[a[i]].size() >= 2 && (Y(st[a[i]].back()) - Y(st[a[i]][st[a[i]].size() - 2])) <= K(i) * (X(st[a[i]].back()) - X(st[a[i]][st[a[i]].size() - 2])))
            st[a[i]].pop_back();
        f[i] = f[st[a[i]].back() - 1] + a[i] * (cnt[i] - cnt[st[a[i]].back()] + 1) * (cnt[i] - cnt[st[a[i]].back()] + 1);
    }
    printf("%lld\n", f[n]);
    return 0;
}
