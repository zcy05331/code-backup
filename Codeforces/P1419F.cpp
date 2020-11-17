#include <bits/stdc++.h>

#define R register
#define ll long long
#define pir std::pair<ll, ll>
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) (((a) + (b)) % mod)
#define It std::map<ll, std::vector<ll>>::iterator

const ll MaxN = 1e3 + 10;

ll n, x[MaxN], y[MaxN], f[MaxN];
std::unordered_map<ll, ll> trash;
std::map<ll, std::vector<ll>> lx, ly;
std::vector<std::pair<ll, ll>> X, Y, line;

ll Abs(ll x) { return (x < 0) ? (-x) : x; }
ll cmpx(ll a, ll b) { return x[a] < x[b]; }
ll cmpy(ll a, ll b) { return y[a] < y[b]; }

ll getf(ll x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

void merge(ll x, ll y)
{
    ll fx = getf(x), fy = getf(y);
    if (fx != fy) f[fx] = fy;
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

ll check(ll mid)
{
    trash.clear();
    for (ll i = 1; i <= n; i++)
        f[i] = i;
    for (It it = lx.begin(); it != lx.end(); it++)
    {
        std::vector<ll> &v = it->second;
        for (ll i = 1; i < v.size(); i++)
            if (Abs(y[v[i]] - y[v[i - 1]]) <= mid)
                merge(v[i], v[i - 1]);
    }
    for (It it = ly.begin(); it != ly.end(); it++)
    {
        std::vector<ll> &v = it->second;
        for (ll i = 1; i < v.size(); i++)
            if (Abs(x[v[i]] - x[v[i - 1]]) <= mid)
                merge(v[i], v[i - 1]);
    }
    ll siz = 0;
    for (ll i = 1; i <= n; i++)
        // getf(i), printf("%lld ", f[i]),
        siz += (trash[getf(i)] == 0), trash[getf(i)] = 1;
    // printf("# %lld %lld\n", mid, siz);
    if (siz == 1)
        return 1;
    else if (siz == 2)
    {
        for (ll i = 1; i <= n; i++)
            for (ll j = i + 1; j <= n; j++)
                if (f[i] != f[j])
                {
                    if (Abs(x[i] - x[j]) == 0 && Abs(y[i] - y[j]) <= 2 * mid)
                        return 1;
                    if (Abs(y[i] - y[j]) == 0 && Abs(x[i] - x[j]) <= 2 * mid)
                        return 1;
                    if (Abs(x[i] - x[j]) <= mid && Abs(y[i] - y[j]) <= mid)
                        return 1;
                }
    }
    else if (siz == 3)
    {
        line.clear();
        for (It it = lx.begin(); it != lx.end(); it++)
        {
            std::vector<ll> &v = it->second;
            for (ll i = 1; i < v.size(); i++)
                if (f[v[i]] != f[v[i - 1]])
                    line.push_back(mp(v[i], v[i - 1]));
        }
        for (It it = ly.begin(); it != ly.end(); it++)
        {
            std::vector<ll> &v = it->second;
            for (ll i = 1; i < v.size(); i++)
                if (f[v[i]] != f[v[i - 1]])
                    line.push_back(mp(v[i], v[i - 1]));
        }
        for (auto li : line)
        {
            ll l = li.first, r = li.second;
            for (ll i = 1; i <= n; i++)
            {
                if (f[l] != f[i] && f[i] != f[r])
                {
                    if (x[l] == x[r])
                    {
                        if (Abs(y[l] - y[i]) <= mid && Abs(y[r] - y[i]) <= mid)
                            if (Abs(x[l] - x[i]) <= mid)
                                return 1;
                    }
                    else if (Abs(x[l] - x[i]) <= mid && Abs(x[r] - x[i]) <= mid)
                        if (Abs(y[l] - y[i]) <= mid)
                            return 1;
                }
            }
        }
    }
    else if (siz == 4)
    {
        X.clear(), Y.clear();
        for (It it = lx.begin(); it != lx.end(); it++)
        {
            std::vector<ll> &v = it->second;
            for (ll i = 1; i < v.size(); i++)
                if (f[v[i]] != f[v[i - 1]])
                    X.push_back(mp(v[i], v[i - 1]));
        }
        for (It it = ly.begin(); it != ly.end(); it++)
        {
            std::vector<ll> &v = it->second;
            for (ll i = 1; i < v.size(); i++)
                if (f[v[i]] != f[v[i - 1]])
                    Y.push_back(mp(v[i], v[i - 1]));
        }
        for (auto x1 : X)
        {
            for (auto y1 : Y)
            {
                ll a = x1.first, b = x1.second;
                ll c = y1.first, d = y1.second;
                if (f[a] != f[c] && f[a] != f[d])
                    if (f[b] != f[c] && f[b] != f[d])
                        if (Abs(x[a] - x[c]) <= mid && Abs(x[a] - x[d]) <= mid)
                            if (Abs(y[c] - y[a]) <= mid && Abs(y[c] - y[b]) <= mid)
                                return 1;
            }
        }
    }
    return 0;
}

signed main()
{
    n = read();
    for (ll i = 1; i <= n; i++)
    {
        x[i] = read(), y[i] = read();
        lx[x[i]].push_back(i);
        ly[y[i]].push_back(i);
    }
    for (It it = lx.begin(); it != lx.end(); it++)
    {
        std::vector<ll> &v = it->second;
        std::sort(v.begin(), v.end(), cmpy);
    }
    for (It it = ly.begin(); it != ly.end(); it++)
    {
        std::vector<ll> &v = it->second;
        std::sort(v.begin(), v.end(), cmpx);
    }
    ll l = 1, r = 0x7f7f7f7f;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l == 0x7f7f7f7f)
        l = -1;
    printf("%lld\n", l);
    return 0;
}