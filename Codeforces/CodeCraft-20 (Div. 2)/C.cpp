#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

int n, m, p;
int cnt = 0, ans = 0;
int a[MaxN], b[MaxN];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % p)
        {
            cnt = i;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (b[i] % p)
        {
            ans = cnt + i;
            break;
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    solve(), printf("%d\n", ans);
    return 0;
}
