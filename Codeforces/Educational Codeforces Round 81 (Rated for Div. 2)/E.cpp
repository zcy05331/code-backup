#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll N = 2e5 + 10;
ll n;
ll p[N], a[N], s[N], posp[N], minn[N << 2], tag[N << 2];
void pushdown(ll id)
{
    if (tag[id])
    {
        tag[id << 1] += tag[id];
        tag[id << 1 | 1] += tag[id];
        minn[id << 1] += tag[id];
        minn[id << 1 | 1] += tag[id];
        tag[id] = 0;
    }
}
void update(ll a, ll b, ll l, ll r, ll id, ll v)
{
    if (a <= l && r <= b)
    {
        minn[id] += v;
        tag[id] += v;
        return;
    }
    pushdown(id);
    ll mid = l + r >> 1;
    if (a <= mid)
        update(a, b, l, mid, id << 1, v);
    if (b > mid)
        update(a, b, mid + 1, r, id << 1 | 1, v);
    minn[id] = std::min(minn[id << 1], minn[id << 1 | 1]);
}

signed main()
{
    scanf("%d", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%d", &p[i]), posp[p[i]] = i;
    for (ll i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (ll i = 1; i <= n; i++)
    {
        s[0] += a[i];
        if (i < n)
            update(i, i, 1, n - 1, 1, s[0]);
    }
    ll ans = minn[1];
    for (ll i = 1; i <= n; i++)
    {
        if (posp[i] == 1)
        {
            update(1, n - 1, 1, n - 1, 1, -a[posp[i]]);
            ans = std::min(ans, minn[1]);
            continue;
        }
        if (posp[i] == n)
        {
            update(1, n - 1, 1, n - 1, 1, a[posp[i]]);
            ans = std::min(ans, minn[1]);
            continue;
        }
        update(1, posp[i] - 1, 1, n - 1, 1, a[posp[i]]);
        update(posp[i], n - 1, 1, n - 1, 1, -a[posp[i]]);
        ans = std::min(ans, minn[1]);
    }
    printf("%lld\n", ans);
    return 0;
}