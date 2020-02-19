#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
ll ans;
int t, n, l, r, x, k;
int a, b;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}
int main()
{   
    t = read(), n = read(), l =read(), r = read(), x = read(), k = read();
    int now = 1, v = l, tmp = 0;
    for(int i = 1; i <= t; i++)
    {
        a = read(), b = read();
        if(a == 0)
            ++now, v = l;
        else if(a == 1)
            --now, v = r;
        if(now == 0 || now == n + 1)
            return 0 * printf("-1");
        if(b == 1)   
            v = std::min(v + x, r);
        if(v == r)
            ++tmp;
        else tmp = 0;
        ans += (ll)now * v;
        if(tmp == k)
            break;
    }  
    printf("%lld", ans);
    return 0;
}
