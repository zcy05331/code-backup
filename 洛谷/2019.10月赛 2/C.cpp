#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

ll a, b, flag = 1;

int main()
{
    scanf("%lld%lld", &a, &b);
    if ((a == 0 && b == 0) || (a * a == 4 * b))
        return 0 * printf("inf\n");
    ll ans = 0, s = 4 * b - a * a;
    // printf("%lld\n", s);
    if (s >= 0)
    {
        for (ll i = 1; i * i <= s; i++)
        {
            if (s % i == 0)
            {
                ll c = (s / i);
                if ((c - i - a * 2) % 4 == 0 && (c + i) % 4 == 0 && (c - (i)) >= (a * 2))
                    ++ans;
            }
        }
        printf("%lld\n", ans);
    }
    else
    {
        for (ll i = 1; i * i <= -s; i++)
        {
            if (s % i == 0)
            {
                ll c = (s / i);
                //printf("%lld %lld\n", i, c);
                if ((i - c - 2 * a) % 4 == 0 && (i - c) >= (a * 2) && (i - c - 2 * a) % 4 == 0)
                    ++ans;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
