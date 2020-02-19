#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

int n;
int a[MaxN], b[MaxN], bpos[MaxN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]), bpos[b[i]] = i;
    int s = bpos[1];
    if (bpos[1])
    {
        int m = n - s + 1;
        for (int i = s; i <= n; i++)
        {
            if (b[i] != i - s + 1)
            {
                m = 0;
                break;
            }
        }
        for (int i = m + 1; i <= n; i++)
        {
            if (bpos[i] >= i - m)
            {
                m = 0;
                break;
            }
        }
        if (m)
            return 0 * printf("%d\n", n - m);
    }
    int cnt = 0, x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (bpos[i] - i < 0)
            cnt++;
        x = cmax(x, bpos[i] - i + 1);
    }
    if (cnt == 0)
        return 0 * printf("%d\n", n);
    else
        printf("%d\n", x + n);
    return 0;
}
