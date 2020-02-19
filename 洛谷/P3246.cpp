#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 1e5 + 10;

struct query
{
    ll l, r, id, pos;
};

query q[MaxN];
ll n, m, size;
ll a[MaxN], f[MaxN][2], pre[MaxN], sub[MaxN];
ll lg2[MaxN], pow2[20], pos[MaxN][20], Ans[MaxN];

ll minn(ll x, ll y) { return (a[x] < a[y]) ? x : y; }
ll cmp(query a, query b) { return (a.pos == b.pos) ? (a.r < b.r) : (a.pos < b.pos); }

ll qry(ll l, ll r)
{
    ll k = lg2[r - l + 1];
    return minn(pos[l][k], pos[r - pow2[k] + 1][k]);
}

ll queryl(ll l, ll r)
{
    ll k = qry(l - 1, r);
    return a[k] * (r - k + 1) + f[l - 1][1] - f[k][1];
}

ll queryr(ll l, ll r)
{
    ll k = qry(l, r + 1);
    return a[k] * (k - l + 1) + f[r + 1][0] - f[k][0];
}

void prework()
{
    std::vector<ll> st;
    a[0] = -(1e9 + 7), st.push_back(0);
    for (ll i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        pre[i] = st.back(), st.push_back(i);
    }
    st.clear();
    a[n + 1] = -(1e9 + 7), st.push_back(n + 1);
    for (ll i = n; i; i--)
    {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        sub[i] = st.back(), st.push_back(i);
    }
    pow2[0] = 1, a[0] = a[n + 1] = 0;
    for (ll j = 1; j <= 18; j++)
    {
        pow2[j] = pow2[j - 1] << 1;
        for (ll i = 1; i <= n - pow2[j - 1] + 1; i++)
            pos[i][j] = minn(pos[i][j - 1], pos[i + pow2[j - 1]][j - 1]);
    }
}

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

signed main()
{
    n = read(), m = read(), lg2[0] = -1;
    for (ll i = 1; i <= n; i++)
        a[i] = read(), pos[i][0] = i, lg2[i] = lg2[i >> 1] + 1;
    prework(), size = pow(n, 0.5);
    for (ll i = 1; i <= m; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1, cmp);
    for (ll i = 1; i <= n; i++)
        f[i][0] = f[pre[i]][0] + a[i] * (i - pre[i]);
    for (ll i = n; i; i--)
        f[i][1] = f[sub[i]][1] + a[i] * (sub[i] - i);
    ll l = 1, r = 0, ans = 0;
    for (ll i = 1; i <= m; i++)
    {
        while (l > q[i].l)
            ans += queryl(l, r), l--;
        while (r < q[i].r)
            ans += queryr(l, r), r++;
        while (l < q[i].l)
            ans -= queryl(l + 1, r), ++l;
        while (r > q[i].r)
            ans -= queryr(l, r - 1), --r;
        Ans[q[i].id] = ans;
    }
    for (ll i = 1; i <= m; i++)
        printf("%lld\n", Ans[i]);
    return 0;
}
