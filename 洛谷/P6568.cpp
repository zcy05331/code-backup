#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int n, k, a[MaxN];

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

int main()
{   
    int now = 0, ans = 0;
    n = read(), k = read() + 1;
    for(int i = 1; i <= n; i++)
        a[i] = read();
    for(int i = 1; i <= k; i++)
        now += a[i];
    ans = std::max(ans, now);
    for(int i = k + 1; i <= n; i++)
    {
        now -= a[i - k], now += a[i];
        ans = std::max(ans, now);
    }
    printf("%d\n", ans);
    return 0;
}
