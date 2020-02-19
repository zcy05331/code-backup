#include <bits/stdc++.h>

# define ll long long
const int MaxN = 100;

ll n, ans, a[MaxN], p[101];

inline void work(ll x)
{
    for(int i = 62; i >= 0; i--)
    {
        if((x >> (1ll * i)) == 0)
            continue;
        if(!p[i])
        {
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}

int main()
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), work(a[i]);
    for(int i = 62; i >= 0; i--)
        if((ans ^ p[i]) > ans)
            ans ^= p[i];
    printf("%lld\n", ans);
    return 0;
}