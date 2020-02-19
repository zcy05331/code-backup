#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
int n, t;
int s[1001], d[1010];
int main()
{
    int ans = 1;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &s[i], &d[i]);
    for (int i = 1; i <= n; i++)
    {
        while (s[i] < t)
            s[i] += d[i];
    }
    int min = 1e9;
    for (int i = 1; i <= n; i++)
    {
        if (min > s[i])
        {
            ans = i;
            min = s[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
