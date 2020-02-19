# include <bits/stdc++.h>

# define ll long long

const int MaxN = 500010;

int n, m, k;

ll fac[MaxN], inv[MaxN];

int prework()
{
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i <= n + m; i++)
        fac[i] = fac[i - 1] * i % k, inv[i] = (k - k / i) * inv[k % i] % k;
    for(int i = 2; i <= n + m; i++)
        inv[i] = inv[i - 1] * inv[i] % k;
}

ll lucas(int n, int m, int k)
{
    if(m < n)
        return 0;
    else if(m < k)
        return fac[m] * inv[n] * inv[m - n] % k;
    else 
        return lucas(n / k, m / k, k) * lucas(n % k, m % k, k) % k;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        prework();
        printf("%lld\n", lucas(m, n + m, k));
    }
    return 0;
}