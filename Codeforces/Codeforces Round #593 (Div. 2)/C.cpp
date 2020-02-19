#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e2 + 10;

int n, cnt, ans[MaxN][MaxN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        if (i & 1)
        {
            for (register int j = 1; j <= n; ++j)
                ans[j][i] = ++cnt;
        }
        else
        {
            for (register int j = n; j >= 1; --j)
                ans[j][i] = ++cnt;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", ans[i][j]);
        puts("");
    }
    return 0;
}
