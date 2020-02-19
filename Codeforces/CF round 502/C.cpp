#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);
    int x = int(sqrt(n));
    if(x * x < n)x++;
    for(int i = 1; i <= x; i++)
    {
        for(int j = i * x; j > (i - 1) * x; j--)
        {
            if(j <= n)printf("%d ", j);
        }
    }
    return 0;
}