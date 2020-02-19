#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

int n, k, a[MaxN], s[MaxN];

void query(int &x, int &y)
{
    printf("? ");
    for (int i = 1; i <= k; i++)
        printf("%d ", a[i]);
    puts(""), fflush(stdout), scanf("%d%d", &x, &y);
}

int main()
{
    int x, y, z, w;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    query(x, y);
    for (int i = 1; i <= k; i++)
        a[i] = ((i == x) ? n : i);
    query(z, w);
    (w > y) ? (w = 1) : (w = -1);
    for (int i = 1; i <= k; i++)
    {
        if (i != x)
        {
            int p, q;
            for (int j = 1; j <= k; j++)
                a[j] = ((j == i) ? n : j);
            query(p, q);
            (p == x) ? (s[i] = w) : (s[i] = -w);
        }
    }
    int ans = 1;
    for (int i = 1; i <= k; i++)
        ans += (s[i] == -1);
    printf("! %d\n", ans);
    fflush(stdout);
    return 0;
}
