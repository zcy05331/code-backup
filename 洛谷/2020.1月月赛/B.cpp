#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int n, m, k;
bool a[MaxN];

inline int read()
{
    R int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{   
    n = read(), m = read(), k = read();
    for(R int i = 1; i <= m; ++i)
    {
        R int x = read();
        while(!a[x])
            a[x] = 1, x = (x + k) % n;
    }
    R int ans = 0;
    for(R int i = 0; i < n; ++i)
        if(!a[i])
            ++ans;
    printf("%d\n", ans);
    return 0;
}
