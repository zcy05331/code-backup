#include <bits/stdc++.h>

int main()
{
    int suma = 0,sumb = 0;
    int a,b;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        suma += a;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b);
        sumb += b;
    }
    if (suma >= sumb)
        puts("Yes");
    else
        puts("No");
    return 0;
}