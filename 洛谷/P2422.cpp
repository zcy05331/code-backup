#include <bits/stdc++.h>
const int MaxN = 100010;
int f[MaxN], a[MaxN], s[MaxN];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
    {
        
    }
    return 0;
}