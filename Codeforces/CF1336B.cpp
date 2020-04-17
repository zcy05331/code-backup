#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int Max = 2e9;
const int Min = -1e9;
const int MaxN = 2e5 + 10;

ll n, m, k, ans;
std::set<ll> R, G, B;
ll r[MaxN], g[MaxN], b[MaxN];

ll sqr(ll x) { return x * x; }

ll sub(ll x, std::set<ll> &y)
{
    if (x == 2000000000) return x;
    return *y.upper_bound(x);
}

ll pre(ll x, std::set<ll> &y)
{
    ll res = *y.lower_bound(x);
    if (x == -1000000000) return x;
    if (res > x) res = *(--y.lower_bound(x));
    return res;
}

void init()
{
    ans = 0x7f7f7f7f7f7f7f7fll;
    R.clear(), R.insert(-1e9), R.insert(2e9);
    G.clear(), G.insert(-1e9), G.insert(2e9);
    B.clear(), B.insert(-1e9), B.insert(2e9);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%lld%lld%lld", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &r[i]), R.insert(r[i]);
        for (int i = 1; i <= m; i++)
            scanf("%lld", &g[i]), G.insert(g[i]);
        for (int i = 1; i <= k; i++)
            scanf("%lld", &b[i]), B.insert(b[i]);
        for (int i = 1; i <= n; i++)
        {
            ll gr[2] = {}, bl[4] = {};
            gr[0] = pre(r[i], G), gr[1] = sub(r[i], G);
            bl[0] = pre(gr[0], B), bl[1] = sub(gr[0], B);
            bl[2] = pre(gr[1], B), bl[3] = sub(gr[1], B);
            for (int j = 0; j < 2; j++)
            {
                for (int l = 0; l < 4; l++)
                    if (gr[j] != Max && gr[j] != Min && bl[l] != Max && bl[l] != Min)
                        ans = std::min(ans, sqr(r[i] - gr[j]) + sqr(gr[j] - bl[l]) + sqr(bl[l] - r[i]));
            }
        }
        for (int i = 1; i <= m; i++)
        {
            ll gr[2] = {}, bl[4] = {};
            gr[0] = pre(g[i], R), gr[1] = sub(g[i], R);
            bl[0] = pre(gr[0], B), bl[1] = sub(gr[0], B);
            bl[2] = pre(gr[1], B), bl[3] = sub(gr[1], B);
            for (int j = 0; j < 2; j++)
            {
                for (int l = 0; l < 4; l++)
                    if (gr[j] != Max && gr[j] != Min && bl[l] != Max && bl[l] != Min)
                        ans = std::min(ans, sqr(g[i] - gr[j]) + sqr(gr[j] - bl[l]) + sqr(bl[l] - g[i]));
            }
        }
        for (int i = 1; i <= k; i++)
        {
            ll gr[2] = {}, bl[4] = {};
            gr[0] = pre(b[i], R), gr[1] = sub(b[i], R);
            bl[0] = pre(gr[0], G), bl[1] = sub(gr[0], G);
            bl[2] = pre(gr[1], G), bl[3] = sub(gr[1], G);
            for (int j = 0; j < 2; j++)
            {
                for (int l = 0; l < 4; l++)
                    if (gr[j] != Max && gr[j] != Min && bl[l] != Max && bl[l] != Min)
                        ans = std::min(ans, sqr(b[i] - gr[j]) + sqr(gr[j] - bl[l]) + sqr(bl[l] - b[i]));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
