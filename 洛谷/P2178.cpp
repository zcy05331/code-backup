#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

char s[MaxN];
ll sa[MaxN], rk[MaxN], buc[MaxN], old[MaxN], h[MaxN], a[MaxN];
ll n, m, f[MaxN], id[MaxN], ans[MaxN], sum[MaxN], min[MaxN], max[MaxN], size[MaxN];

ll cmp1(ll x, ll y) { return h[x] > h[y]; }
ll cmp(ll x, ll y, ll w) { return (old[x] == old[y] && old[x + w] == old[y + w]); }

ll getf(ll x)
{
    if (f[x] != x)
        f[x] = getf(f[x]);
    return f[x];
}

void merge(ll x, ll y)
{
    ll ht = h[x];
    x = getf(x), y = getf(y);
    sum[ht] += size[x] * size[y], ans[ht] = std::max(ans[ht], std::max(min[x] * min[y], max[x] * max[y]));
    max[x] = std::max(max[x], max[y]), min[x] = std::min(min[x], min[y]), f[y] = x, size[x] += size[y];
}

void Sort()
{
    for (ll i = 0; i <= m; i++)
        buc[i] = 0;
    for (ll i = 1; i <= n; i++)
        buc[rk[i]]++;
    for (ll i = 1; i <= m; i++)
        buc[i] += buc[i - 1];
    for (ll i = n; i; i--)
        sa[buc[rk[old[i]]]--] = old[i];
}

void SuffixSort()
{
    m = 300;
    for (ll i = 1; i <= n; i++)
        rk[i] = s[i], old[i] = i;
    Sort();
    for (ll w = 1, p = 0; p < n; m = p, w <<= 1)
    {
        p = 0;
        for (ll i = 1; i <= w; i++)
            old[++p] = n - w + i;
        for (ll i = 1; i <= n; i++)
            if (sa[i] > w)
                old[++p] = sa[i] - w;
        Sort(), std::swap(old, rk), rk[sa[1]] = p = 1;
        for (ll i = 2; i <= n; i++)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    ll k = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (k)
            --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k])
            ++k;
        h[rk[i]] = k;
    }
}

int main()
{
    scanf("%lld\n%s", &n, s + 1), SuffixSort();
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; i++)
        f[i] = id[i] = i, max[i] = min[i] = a[sa[i]], size[i] = 1, ans[i] = -0x7f7f7f7f7f7f7f7f;
    std::sort(id + 1, id + n + 1, cmp1);
    for (ll i = 1; i <= n; i++)
        if (getf(id[i]) != getf(id[i] - 1))
            merge(id[i], id[i] - 1);
    for (ll i = n - 2; ~i; i--)
        sum[i] += sum[i + 1], ans[i] = std::max(ans[i], ans[i + 1]);
    for (int i = 0; i < n; i++)
        printf("%lld %lld\n", sum[i], !sum[i] ? 0 : ans[i]);
    return 0;
}
