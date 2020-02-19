#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
const int MaxN = 500010;
int n, in, de;
int a[MaxN], vis[MaxN], cnt[MaxN], inc[MaxN], dec[MaxN];
int cmp(int a, int b)
{
    return a > b;
}
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
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read(), ++cnt[a[i]];
        if (cnt[a[i]] >= 3)
            return 0 * printf("NO");
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[a[i]] == 1)
            inc[++in] = a[i];
        else if (cnt[a[i]] == 2 && vis[a[i]] == 1)
            dec[++de] = a[i];
        else
            inc[++in] = a[i], ++vis[a[i]];
    }
    std::sort(inc + 1, inc + in + 1);
    std::sort(dec + 1, dec + de + 1, cmp);
    printf("YES\n");
    printf("%d\n", in);
    for (int i = 1; i <= in; i++)
        printf("%d ", inc[i]);
    puts("");
    printf("%d\n", de);
    for (int i = 1; i <= de; i++)
        printf("%d ", dec[i]);
    puts("");
    return 0;
}
