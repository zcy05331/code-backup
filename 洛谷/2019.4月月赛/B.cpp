// luogu-judger-enable-o2
#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

ll T, k;
ll a[10], b[10];

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

inline void solve1()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld %lld\n", a, b);
}

inline void solve2()
{
    printf("%lld %lld %lld\n", gcd(b[1], b[2]), gcd(b[2], b[3]), gcd(b[3], b[1]));
}

inline void solve3()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
                if (i != j && j != k && k != i)
                    if (gcd(gcd(b[i], b[j]), b[k]) != 1)
                    {
                        ll x = gcd(gcd(b[i], b[j]), b[k]);
                        printf("%lld %lld %lld %lld\n", x, b[i] / x, b[j] / x, b[k] / x);
                        return;
                    }
    }
}

inline void solve4()
{

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                if (i != j && j != k && k != i)
                    if (b[1] % a[i] == 0 && b[2] % a[j] == 0 && b[3] % a[k] == 0)
                    {
                        ll x = b[1] / a[i], y = b[2] / a[j], z = b[3] / a[k];
                        return (void)printf("%lld %lld %lld\n", x, y, z);
                    }
}

inline void solve5()
{
}

int main()
{
    scanf("%lld%lld", &T, &k);
    for (int i = 1; i <= T; i++)
    {
        if (k == 2)
            solve1();
        else
        {
            ll tmp = 1;
            for (int i = 1; i <= (k * (k - 1)) / 2; i++)
            {
                scanf("%lld", &a[i]);
                if (a[i] != 1)
                    tmp = 0;
            }
            for (int i = 1; i <= (k * (k - 1)) / 2; i++)
                scanf("%lld", &b[i]);
            if (tmp && k == 3)
                solve2();
            else if (tmp && k == 4)
                solve3();
            else if (tmp == 0 && k == 3)
                solve2();
            else
                solve3();
        }
    }
    return 0;
}
