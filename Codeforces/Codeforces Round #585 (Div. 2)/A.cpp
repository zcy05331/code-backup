#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    int a[3], k[3], n;
    for (int i = 1; i <= 2; i++)
        scanf("%d", &a[i]);
    for (int j = 1; j <= 2; j++)
        scanf("%d", &k[j]);
    if (k[2] < k[1])
        std::swap(k[2], k[1]), std::swap(a[1], a[2]);
    scanf("%d", &n);
    if((a[1]*(k[1] - 1) + a[2] * (k[2] - 1)) >= n)
        printf("0 ");
    else
        printf("%d ", n - (a[1] * (k[1] - 1) + a[2] * (k[2] - 1)));
    if (a[1] * k[1] >= n)
        printf("%d", n / k[1]);
    else
        printf("%d", a[1] + (n - a[1] * k[1]) / k[2]);
    return 0;
}
