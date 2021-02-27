#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, a[MaxN], s[MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    int T = read();
    while (T--)
    {
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read(), s[i] = std::max(a[i], s[i - 1]);
        int now = n;
        while(now >= 1)
        {
            int tmp = now;
            while(a[tmp] != s[now])
                --tmp;
            for(int i = tmp; i <= now; i++)
                printf("%d ", a[i]);
            now = tmp - 1;
        }
        puts("");
    }
    return 0;
}
