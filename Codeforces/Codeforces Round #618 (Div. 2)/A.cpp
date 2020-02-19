#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e2 + 10;

int n, a[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int zero = 0, sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), zero += (a[i] == 0), sum += a[i];
        if ((sum != 0) && (zero == 0))
        {
            printf("%d\n", 0);
            continue;
        }
        int ans = 0;
        if (sum == 0 && zero == 0)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] == -1)
                    cnt++;
            ans = ((cnt == n) ? 2 : 1);
            printf("%d\n", ans);
        }
        else if (sum != 0 && zero != 0)
        {
            if (zero + sum == 0)
                printf("%d\n", zero + 1);
            else
                printf("%d\n", zero);
        }
        else if (sum == 0 && zero != 0)
            printf("%d\n", zero);
    }
    return 0;
}
