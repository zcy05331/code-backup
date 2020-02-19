#include <bits/stdc++.h>
const int Max = 300010;
int a[Max], b[Max];
long long s1, s2;
int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), s1 = s1 + a[i];
    scanf("%d", &m);
    for (int j = 1; j <= m; j++)
        scanf("%d", &b[j]), s2 = s2 + b[j];
    if (s1 != s2)
    {
        puts("-1");
        return 0;
    }
    int ans = 0;
    int x = 1, y = 1;
    long long suma = a[1], sumb = b[1];
    while (x <= n && y <= m)
    {
        //printf("%d %d\n", x, y);
        if (suma == sumb)
            ans++;
        if (x >= n)
        {
            y++, sumb += b[y];
            continue;
        }
        else if (y >= m)
        {
            x++, suma += a[x];
            continue;
        }
        if (suma == sumb)
        {
            x++, y++;
            suma += a[x];
            sumb += b[y];
        }
        else if(suma > sumb)
        {
            y++;
            sumb += b[y];
        }
        else if(sumb > suma)
        {
            x++;
            suma += a[x];
        }
    }
    printf("%d\n", ans);
    return 0;
}