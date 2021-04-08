#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define Add(a, b, mod) ((a) = sum(a, b, mod))
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 6e2 + 10;

int n, p, a[MaxN][MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int solve()
{
    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            while(a[i][i])
            {
                int rest = a[j][i] / a[i][i];
                for(int k = i; k <= n; k++)
                    Add(a[j][k], p - (ll)a[i][k] * rest % p, p);
                std::swap(a[i], a[j]), res = -res;
            }
            std::swap(a[i], a[j]), res = -res;
        }
    }
    for(int i = 1; i <= n; i++)
        res = (ll)res * a[i][i] % p;
    return (res + p) % p;
}

signed main()
{   
    n = read(), p = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = read();
    printf("%d\n", solve());
    return 0;
}
