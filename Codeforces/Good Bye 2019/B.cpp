#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

int n, a[MaxN], max[MaxN], min[MaxN];

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

int main()
{
    int T = read();
    while (T--)
    {
        n = read(), max[0] = 0, min[0] = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        int flag = 1, l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (abs(a[i] - a[i + 1]) >= 2)
                flag = 0, l = i, r = i + 1;
        }
        if (flag)
            puts("NO");
        else
            printf("YES\n%d %d\n", l, r);
    }
    return 0;
}
