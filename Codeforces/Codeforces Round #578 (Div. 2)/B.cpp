#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e4 + 10;
int n, m, k, h[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        int flag = 1;
        for (int i = 1; i < n; i++)
        {
            if (h[i] >= h[i + 1] - k)
                m += (h[i] - cmax(0, h[i + 1] - k));
            else if (h[i] + m < cmax(0, h[i + 1] - k))
            {
                printf("No\n");
                flag = 0;
                break;
            }
            else if (h[i] + m >= h[i + 1] - k)
                m -= cmax(0, h[i + 1] - k) - h[i];
        }
        if (flag == 1)
            printf("Yes\n");
    }
    return 0;
}
