#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int n, a[MaxN], ans[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), ans[i] = 0;
        ans[1] = ans[n] = 1;
        int l = 1, r = 1;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
                l = r = i;
        for (int i = 2; i < n; i++)
        {
            while ((l > 1) && a[l - 1] <= i)
                --l;
            while ((r < n) && (a[r + 1] <= i))
                ++r;
            if (r - l + 1 == i)
                ans[i] = 1;
        }
        for (int i = 1; i <= n; i++)
            printf("%d", ans[i]);
        puts("");
    }
    return 0;
}
