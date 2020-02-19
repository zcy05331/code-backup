#include <bits/stdc++.h>

const int MaxN = 3e5 + 10;
int n;
int c[MaxN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] != c[n])
        {
            ans = n - i;
            break;
        }
    }
    for (int i = n; i; i--)
    {
        if (c[i] != c[1])
        {
            return 0 * printf("%d\n", std::max(ans, i - 1));
        }
    }
    return 0;
}