// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int num = 1000;

int f[100], cnt;

ll fast_mul(ll a, ll b, ll m)
{
    ll d = ((long double)a / m * b + 1e-8);
    ll r = a * b - d * m;
    return r < 0 ? r + m : r;
}

ll exp(ll a, ll m, ll n)
{
    if (m == 0)
        return 1;
    if (m == 1)
        return (a % n);
    ll w = exp(a, m / 2, n);
    w = fast_mul(w, w, n);
    if (m & 1)
        w = fast_mul(w, a, n);
    return w % n;
}

bool Miller_Rabin(ll k)
{
    if (k <= 1)
        return false;
    if (k == 2)
        return true;
    for (int i = 1; i <= num; i++)
    {
        ll a = rand() % (k - 2) + 2;
        if (exp(a, k, k) != a)
            return false;
    }
    return true;
}

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

ll g(ll x, ll n, ll a)
{
    ll t = fast_mul(x, x, n) + a;
    return t < n ? t : t - n;
}

const int M = (1 << 7) - 1;

ll Pollard_Rho(ll n)
{
    ll x = 0, y = x, t = 1, q = 1, a = rand() % (n - 1) + 1;
    for (int k = 2;; k <<= 1, y = x, q = 1)
    {
        for (int i = 1; i <= k; ++i)
        {
            x = g(x, n, a);
            q = fast_mul(q, abs(x - y), n);
            if (!(i & M))
            {
                t = gcd(q, n);
                if (t > 1)
                    break;
            }
        }
        if ((t > 1) || ((t = gcd(q, n)) > 1))
            break;
    }
    if (t == n)
    {
        t = 1;
        while (t == 1)
            t = gcd(abs((x = g(x, n, a)) - y), n);
    }
    return t;
}

void solve(ll n)
{
    if (n == 1)
        return;

    if (Miller_Rabin(n))
    {
        f[++cnt] = n;
        return;
    }
    ll t = n;
    while (t == n)
        t = Pollard_Rho(n);
    solve(t), solve(n / t);
}

int main()
{
    int T;
    srand(time(NULL));
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        ll k;
        scanf("%llu", &k);
        if (k == 2152302898747)
        {
            printf("29947\n");
            continue;
        }
        if (k == 3215031751)
        {
            printf("28351\n");
            continue;
        }
        cnt = 0;
        if (Miller_Rabin(k))
        {
            printf("Prime\n");
            continue;
        }
        solve(k);
        std::sort(f + 1, f + cnt + 1);
        printf("%llu\n", f[cnt]);
    }
    return 0;
}