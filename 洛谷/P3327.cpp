# include <bits/stdc++.h>

# define ll long long

const int MaxN = 10000005;

int mu[MaxN];

ll cnt, prime[MaxN];

ll p[MaxN], c[MaxN];

inline void getprime(int n)
{
    mu[1] = 1;
    for (register int i = 2; i <= n; ++i)
    {
        if(!p[i])
        {
            prime[++cnt] = i;
            mu[i] = -1;
            c[i] = 1;
        }
        for (register int j = 1; j <= cnt && i * prime[j] <= n; ++j)
        {
            p[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                c[i * prime[j]] = mu[i];
                break;
            }
            else 
            {
                mu[i * prime[j]] = -mu[i];
                c[i * prime[j]] = mu[i] - c[i];
            }
        }
    }
    for (register int i = 1; i <= n; ++i)
        c[i] = c[i - 1] + c[i];
}

int main()
{
    getprime(10000000);
    register int T;
    scanf("%d", &T);
    while(T--)
    {
        register ll n, m;
        scanf("%lld%lld", &n, &m);
        if(n > m)
            std::swap(n, m);
        register ll ans = 0;
        for(register int i = 1, nxt; i <= n; i = nxt + 1)
        {
            nxt = std::min(n / (n / i), m / (m / i));
            ans += (c[nxt] - c[i - 1]) * ((n / i) * (m / i));
        }
        printf("%lld\n", ans);
    }
    return 0;
}