#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int ceil(int i, int j) { return (i / j) + (!!(i % j)); }

int main()
{
    int T, n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        if (n <= 5000)
        {
            int ans = 0;
            for (int i = 1, j; i < n; i++)
            {
                j = n - i;
                if ((i / j) + ceil(j, i) == m) ++ans;
            }
            printf("%d\n", ans);
        }
        else if (n == 1 || m == 1 || m > n)
        {
            printf("0\n");
            continue;
        }
        else if (m == n || m == n - 1)
        {
            printf("1\n");
            continue;
        }
        else
        {
            int ans = 0;
            int a = (n - m + 1) / m, b = n / m;
            if(a < b && b >= (n - b)) ++ans;
            a = ceil(n, m + 1), b = ceil(n + m, m + 1);
            if(a < b && (n - a) >= a) ++ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}
