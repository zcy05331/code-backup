#include <bits/stdc++.h>

int n, m;
int a[101];

int main()
{
    int pmax = 0, sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pmax = (pmax > a[i] ? pmax : a[i]);
        sum += a[i];
    }
    int kmin, kmax;
    kmax = pmax + m;
    kmin = (m + sum) / n;
    if(kmin * n < m + sum)
        kmin++;
    kmin = std::max(kmin, pmax);
    printf("%d %d", kmin, kmax);
    return 0;
}