#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const ll MaxN = 1e5 + 10;

ll n;
ll sum = 0;
std::map<ll, ll> m;
ll a[MaxN], b[MaxN], s[MaxN];

int main()
{
    scanf("%I64d", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%I64d", &a[i]), sum += a[i], m[a[i]]++;
    if (sum == 0)
        return 0 * printf("cslnb");
    if (n == 1)
    {
        if (a[1] % 2 == 0)
            return 0 * printf("cslnb");
        else
            return 0 * printf("sjfnb");
    }
    std::sort(a + 1, a + n + 1);
    ll tmp = 0, now = 0, flag = 1, f = 0;
    for (ll i = 2; i <= n; i++)
    {
        
        if (a[i] == a[i - 1])
        {
            if (a[i] == 0 || i - 2 > 0 && a[i] - 1 == a[i - 2])
                return 0 * printf("cslnb");
            f++;
        }
    }
    if (f > 1)
        return 0 * printf("cslnb");
    sum -= f + (ll)(n * 1ll * (n - 1) / 2ll);
    if ((sum & 1) ^ f)
        printf("sjfnb");
    else
        printf("cslnb");
    return 0;
}
