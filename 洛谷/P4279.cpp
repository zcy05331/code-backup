#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e2 + 10;

int n, sum, num, a[MaxN];

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
        n = read(), sum = num = 0;
        for(int i = 1; i <= n; i++)
            a[i] = read(), sum += a[i], num ^= a[i];
        if(sum == n)
            puts((sum & 1) ? "Brother" : "John");
        else puts(num ? "John" : "Brother");
    }
    return 0;
}
