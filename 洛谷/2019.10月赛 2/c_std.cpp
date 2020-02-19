#include <cstdio>
typedef long long ll;
ll a, b, t, abst, ans;
inline bool F(ll i, ll j) { return j - i >= a + a && !(j - i - a - a & 3) && !(i + j & 3); }
int main()
{
    scanf("%lld%lld", &a, &b);
    t = 4 * b - a * a;
    if (!t)
        return 0 * puts("inf");
    if (t > 0)
    {
        for (ll i = 1; i * i <= t; i++)
            if (t % i == 0)
                ans += F(i, t / i);
    }
    if (t < 0)
    {
        abst = -t;
        for (ll i = 1; i * i <= abst; i++)
            if (abst % i == 0)
                ans += F(t / i, i);
    }
    printf("%lld", ans);
    return 0;
}