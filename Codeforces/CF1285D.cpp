#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e6 + 10;
const int lim = (1 << 29);

int n, cnt = 1, a[MaxN], num[MaxN], ch[MaxN][2];

inline void insert(int x)
{
    int now = 1;
    for (int i = lim; i; i >>= 1)
    {
        if (ch[now][x & i])
            now = ch[now][x & i];
        else
            ++num[now], now = ch[now][x & i] = ++cnt;
    }
}

int query(int x, int k)
{
    if (!num[x])
        return 0;
    int ans = 1e9;
    if (ch[x][0])
        ans = std::min(ans, query(ch[x][0], k >> 1));
    if (ch[x][1])
        ans = std::min(ans, query(ch[x][1], k >> 1));
    return ((num[x] == 1) ? ans : (ans + k));
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
    for (int i = 1; i <= n; i++)
        a[i] = read(), insert(a[i]);
    printf("%d\n", query(1, lim));
    return 0;
}
