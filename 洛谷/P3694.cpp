#include <bits/stdc++.h>

#define R register
#define ll long long
#define lowbit(x) ((x) & (-(x)))
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxM = 21;
const int MaxN = 2e5 + 10;

int n, m;
int f[1 << MaxM], len[1 << MaxM];
int a[MaxN], cnt[MaxM], sum[MaxN][MaxM];

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
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j];
        a[i] = read(), cnt[a[i]]++, sum[i][a[i]]++;
    }
    for(int i = 1; i < (1 << m); i++)
        len[i] = len[i ^ lowbit(i)] + cnt[__builtin_ffs(lowbit(i))];
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for(int i = 1; i < (1 << m); i++)
    {
        for(int j = 0; j < m; j++)
            if(i & (1 << j))
            f[i] = std::min(f[i], f[i ^ (1 << j)] + cnt[j + 1] - sum[len[i]][j + 1] + sum[len[i] - cnt[j + 1]][j + 1]);
    }
    printf("%d\n", f[(1 << m) - 1]);
    return 0;
}
