#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

ll n, m;
ll ans = 0, last;
ll f[MaxN], g[MaxN], cnt[MaxN], sat[MaxN];
std::map<ll, ll> map;

int main()
{
    scanf("%lld%lld", &n, &m), last = m;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &f[i]);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &g[i]), map[g[i]]++;
    std::sort(f + 1, f + n + 1);
    std::sort(g + 1, g + m + 1);
    for (int i = 1; i <= n; i++)
    {
        ans += f[i];
        cnt[i] = m - 1;
        if (map[f[i]])
            map[f[i]]--, --last;
    }
    std::map<ll, ll>::iterator it = map.end();
    --it;
    for (int i = 1; i <= n; i++)
    {
        while (cnt[i] && last)
        {
            while (cnt[i])
            {
                if (f[i] <= it->first)
                {
                    --it->second, --cnt[i], ans += it->first;
                    if (it->second == 0)
                        --it;
                    if (it == map.begin())
                        break;
                }
                else
                    break;
            }
            if (last == 0)
                break;
        }
        if (cnt[i])
            ans += (ll)(f[i] * cnt[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
