#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    int n, maxn = -1, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (maxn < a[i])
            maxn = a[i];
    }
    for (int i = 0; i < n; i++)
        ans += (maxn - a[i]);
    printf("%d", ans);
    return 0;
}
