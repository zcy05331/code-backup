#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
int n, a[500010];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), a[i + n] = a[i];
    int ans = 0, tmp = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (a[i] == 1)
            ++tmp;
        else
        {
            ans = std::max(ans, tmp);
            tmp = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
