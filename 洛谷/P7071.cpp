#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

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

signed main()
{   
    int x = read();
    if(x & 1) return 0 * puts("-1");
    for(int i = 30; ~i; i--)
        if(x & (1 << i)) printf("%d ", (1 << i));
    return 0;
}
