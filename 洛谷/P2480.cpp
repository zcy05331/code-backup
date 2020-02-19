#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
const int mod = 999911658;

ll n, g, val;
ll fac[100010], a[10], b[10] = {0, 2, 3, 4679, 35617};

ll fast_pow(ll a, ll b, ll p)
{
    ll ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        ret = ret * (b & 1 ? a : 1) % p;
    return ret;
}

void prework(ll n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % n;
}

ll C(ll n, ll m, ll p) //组合数
{
    if (n < m)
        return 0;
    return fac[n] * fast_pow(fac[m], p - 2, p) % p * fast_pow(fac[n - m], p - 2, p) % p;
}

ll lucas(ll n, ll m, ll p)
{
    if (n < m)
        return 0;
    if (n == 0)
        return 1;
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

void crt()
{
    for (int i = 1; i <= 4; i++)
        val = (val + a[i] * (mod / b[i]) % mod * fast_pow(mod / b[i], b[i] - 2, b[i])) % mod;
}

int main()
{
    scanf("%lld%lld", &n, &g);
    if (g % (mod + 1) == 0)
        return 0 * printf("0");
    for (int k = 1; k <= 4; k++)
    {
        prework(b[k]);
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                a[k] = (a[k] + lucas(n, i, b[k])) % b[k];
                if (i * i != n)
                    a[k] = (a[k] + lucas(n, n / i, b[k]) % b[k]);
            }
        }
    } 
    crt();
    printf("%lld", fast_pow(g, val, mod + 1));
    return 0;
}
