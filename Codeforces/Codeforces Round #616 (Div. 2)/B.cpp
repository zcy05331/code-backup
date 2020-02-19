#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

int n, a[MaxN], ok[MaxN][2];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), ok[i][0] = ok[i][1] = 0;
        int okl = 1, okr = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < i - 1)
                okl = 0;
            if (okl)
                ok[i][0] = 1;
        }
        for (int i = n; i; i--)
        {
            if (a[i] < n - i)
                okr = 0;
            if (okr)
                ok[i][1] = 1;
        }
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ok[i][0] && ok[i][1])
                flag = 1;
        }
        printf(flag ? "Yes\n" : "No\n");
    }
    return 0;
}
