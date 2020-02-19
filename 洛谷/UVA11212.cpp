#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int a[20];
int n, tot, ans;

inline int check(int a[])
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] != a[i - 1] + 1)
            ++cnt;
    return cnt;
}

inline void dfs(int m, int dep)
{
    int tot = check(a);
    if (tot + dep * 3 > m * 3)
        return;
    if (tot == 0)
    {
        ans = 1;
        return;
    }
    int tmp[20], tmp1[20];
    memcpy(tmp, a, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1] + 1)
        {
            for (int j = i; j <= n; j++)
            {
                if (j < n && a[j + 1] == a[j] + 1)
                    continue;
                for (int k = i; k <= j; k++)
                    tmp1[k] = a[k];
                for (int k = j + 1; k <= n; k++)
                {
                    if (k < n && a[k] + 1 == a[k + 1])
                        continue;
                    for (int l = i, l1 = j + 1; l1 <= k; l++, l1++)
                        a[l] = a[l1];
                    for (int l = i + k - j, l1 = i; l1 <= j; l++, l1++)
                        a[l] = tmp1[l1];
                    dfs(m, dep + 1);
                    memcpy(a, tmp, sizeof(tmp));
                }
            }
        }
    }
}

int main()
{
    int c = 0;
    while (scanf("%d", &n) && n)
    {
        ++c;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        tot = check(a), ans = 0;
        if (tot == 0)
        {
            printf("Case %d: 0\n", c);
            continue;
        }
        for (int i = 1; i <= 5; i++)
        {
            dfs(i, 0);
            if (ans)
            {
                printf("Case %d: %d\n", c, i);
                break;
            }
        }
    }
    return 0;
}
