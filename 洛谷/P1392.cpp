# include <bits/stdc++.h>

const int MaxN = 100010;

int a[MaxN], b[MaxN];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i]);
        std::sort(a + 1, a + m + 1);
        for(int i = 1; i <= k; i++)
        {
            
        }
    }
    return 0;
}