#include <bits/stdc++.h>

#define ll long long

#define calc(x) (x < 2 ? 0 : x * (x - 1) / 2)

const int MaxN = 200010;

ll a[MaxN];
std::map<int, ll> m;

int main()
{
    ll n, k;
    ll ans = 0;
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        m[i - a[i]]++;
        m[i + a[i]]++;
    }
    for(std::map<int, ll>::iterator it = m.begin(); it != m.end(); it++)
        ans += calc(it->second);
    printf("%lld", ans);
    return 0;
}