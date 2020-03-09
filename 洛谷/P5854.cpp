#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e7 + 10;

int n, top, a[MaxN], lc[MaxN], rc[MaxN], st[MaxN];

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
    n = read();
    for(R unsigned i = 1; i <= n; ++i)
        a[i] = read();
    for(R unsigned i = 1; i <= n; ++i)
    {
        int k = top;
        while(k && a[st[k]] > a[i]) k--;
        if(k < top) lc[i] = st[k + 1];
        if(k) rc[st[k]] = i;
        st[++k] = i, top = k;
    }
    ll lans = 0, rans = 0;
    for(R unsigned i = 1; i <= n; ++i)
        lans ^= (i * 1ll * (lc[i] + 1)), rans ^= (i * 1ll * (rc[i] + 1));
    printf("%lld %lld\n", lans, rans);
    return 0;
}
