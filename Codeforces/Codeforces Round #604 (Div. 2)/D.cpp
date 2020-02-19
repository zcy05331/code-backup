#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;
int ans[MaxN];

int main()
{
    int a[4], b[4], n = 0;
    for (int i = 0; i < 4; i++)
        scanf("%d", &a[i]), n += a[i];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            b[j] = a[j];
        if (b[i] == 0)
            continue;
        int p = i, flag = 1;
        for (int j = 1; j <= n; j++)
        {
            ans[j] = p, --b[p];
            if (p < 0 || p > 3 || b[p] < 0)
            {
                flag = 0;
                break;
            }
            if (p && b[p - 1])
                p--;
            else
                p++;
        }
        if (flag)
        {
            puts("YES");
            for (int j = 1; j <= n; j++)
                printf("%d ", ans[j]);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
