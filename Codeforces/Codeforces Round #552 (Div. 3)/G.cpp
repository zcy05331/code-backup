#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 10000010;

ll n;
ll vis[MaxN];
std::map<ll, ll> m;

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
    n = read();
    ll ans = 1e18;
    std::vector<ll> ans1, ans2;
    for (int i = 1; i <= n; i++)
    {
        ll x = read();
        if (vis[x])
        {
            if (x < ans)
            {
                ans2.clear();
                ans2.push_back(vis[x]);
                ans2.push_back(i);
                ans = x;
            }
        }
        vis[x] = i;
    }
    for (ll i = 1; i <= 1e7; i++)
    {
        ans1.clear();
        for (ll j = i; j <= 1e7; j += i)
        {
            if (vis[j])
                ans1.push_back(j);
            if (ans1.size() >= 2)
                break;
        }
        if(ans1.size() >= 2)
        {
            ll Max = (ans1[0] * ans1[1]) / i;
            if(Max < ans)
            {
                ans = Max;
                ans2.clear();
                ans2.push_back(vis[ans1[0]]);
                ans2.push_back(vis[ans1[1]]);
            }
        }
    }
    std::sort(ans2.begin(), ans2.end());
    for (auto d : ans2)
        printf("%d ", d);
    return 0;
}
