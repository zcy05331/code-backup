#include <bits/stdc++.h>
int n, l, t, ans[10010], sum;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &i);
        scanf("%d", &l);
        int tmp = 0;
        while (scanf("%d", &t) && t)
            tmp = std::max(ans[t], tmp);
        ans[i] = tmp + l;
        sum = std::max(ans[i], sum);
    }
    printf("%d\n", sum);
    return 0;
}