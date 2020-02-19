#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
int n, k1, k2;
int a[MaxN], b[MaxN];

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
    int T = read();
    while(T--)
    {
        int max1 = 0, max2 = 0;
        n = read(), k1 = read(), k2 = read();
        for(int i = 1; i<= k1; i++)
            a[i] = read(), max1 = std::max(a[i], max1);
        for(int i  =1; i <= k2; i++)
            b[i] = read(), max2 = std::max(b[i], max2);
        puts((max1 > max2) ? "YES" : "NO");
    }
    return 0;
}
