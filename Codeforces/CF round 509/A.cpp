#include <bits/stdc++.h>
const int MaxN = 1010;
int a[MaxN];
int main()
{
    int n;
    scanf("%d", &n);
    int pmin = 0x7f7f7f7f;
    int pmax = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pmax = std::max(pmax, a[i]);
        pmin = std::min(pmin, a[i]);
    }
    printf("%d\n", pmax - pmin + 1 - n);
    return 0;
}