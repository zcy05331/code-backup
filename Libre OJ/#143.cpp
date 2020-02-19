#include <bits/stdc++.h>

#define ll long long

const int cnt = 2500;
const int mod[] = {3, 5, 7, 11, 13, 17, 19, 23, 29};

ll fast_mul(ll a, ll b, ll m)
{
    ll d = ((long double)a / m * b + 0.5);
    ll r = a * b - d * m;
    return r < 0 ? r + m : r;
}

ll fast_pow(ll a, ll m, ll n)
{
    ll ret = 1;
    while (m)
    {
        if (m & 1)
            ret = fast_mul(ret, a, n);
        a = fast_mul(a, a, n);
        m >>= 1;
    }
    return ret;
}

bool check(ll k)
{
    if (k <= 1)
        return false;
    if (k == 2)
        return true;
    if (!(k & 1))
        return false;
    ll t = k - 1;
    int now = 0;
    while (!(t & 1))
        t >>= 1, ++now;
    for (int i = 0; i < 9; i++)
    {
        if (mod[i] == k)
            return 1;
        ll x = fast_pow(mod[i], t, k), y = x;
        for (int j = 1; j <= now; j++)
        {
            x = fast_mul(x, x, k);
            if (x == 1 && !(y == 1 || y == k - 1))
                return false;
            y = x;
        }
        if (x != 1)
            return 0;
    }
    return true;
}

int main()
{
    srand(time(NULL));
    ll k;
    while (scanf("%llu", &k) == 1)
        printf(check(k) ? "Y\n" : "N\n");
    return 0;
}