#include <bits/stdc++.h>
int n, a[101], b[101];
int main()
{
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            b[++cnt] = a[i];
        else
            b[n - cnt + 1] = a[i];
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    return 0;
}
