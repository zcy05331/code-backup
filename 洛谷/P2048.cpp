#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

struct node
{
    ll maxp, val;
    ll l, r, pos;
    bool operator<(node x) const { return val < x.val; }
};

ll n, k, l, r;
std::priority_queue<node> q;
ll a[MaxN], lg[MaxN], sum[MaxN], max[MaxN][21], maxp[MaxN][21];

void query(ll l, ll r, ll &val, ll &pos)
{
    ll len = lg[r - l + 1];
    val = std::max(max[l][len], max[r - (1 << len) + 1][len]);
    pos = (max[l][len] > max[r - (1 << len) + 1][len]) ? maxp[l][len] : maxp[r - (1 << len) + 1][len];
}

void prework()
{
    lg[0] = -1;
    for (ll i = 1; i <= n; i++)
        maxp[i][0] = i, max[i][0] = sum[i], lg[i] = lg[i >> 1] + 1;
    for (ll j = 1; j <= 20; j++)
        for (ll i = 1; i <= n - (1 << j) + 1; i++)
            max[i][j] = std::max(max[i][j - 1], max[i + (1 << (j - 1))][j - 1]);
    for (ll j = 1; j <= 20; j++)
        for (ll i = 1; i <= n - (1 << j) + 1; i++)
            maxp[i][j] = ((max[i][j - 1] > max[i + (1 << (j - 1))][j - 1]) ? maxp[i][j - 1] : maxp[i + (1 << (j - 1))][j - 1]);
}

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-') f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{
    n = read(), k = read();
    l = read(), r = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read(), sum[i] = sum[i - 1] + a[i];
    prework();
    for (ll i = 1; i <= n; i++)
    {
        ll pos, val;
        if (i + l - 1 > n) break;
        query(i + l - 1, std::min(i + r - 1, n), val, pos);
        val -= sum[i - 1], pos -= i - 1;
        q.push({pos, val, l, std::min(r, n - i + 1), i});
    }
    ll ans = 0;
    for(ll i = 1; i <= k; i++)
    {
        node x = q.top();
        q.pop(), ans += x.val;
        if(x.maxp > x.l)
        {
            ll pos, val;
            query(x.pos + x.l - 1, x.pos + x.maxp - 2, val, pos);
            val -= sum[x.pos - 1], pos -= x.pos - 1;
            q.push({pos, val, x.l, x.maxp - 1, x.pos});
        }
        if(x.maxp < x.r)
        {
            ll pos, val;
            query(x.pos + x.maxp, x.pos + x.r - 1, val, pos);
            val -= sum[x.pos - 1], pos -= x.pos - 1;
            q.push({pos, val, x.maxp + 1, x.r, x.pos});
        }
    }
    printf("%lld\n", ans);
    return 0;
}
