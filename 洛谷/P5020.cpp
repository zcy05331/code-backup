# include <bits/stdc++.h>

const int MaxN = 25010;

int a[MaxN];
bool f[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans = n;
        std::sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++)
        {
            if(f[a[i]])
            {
                --ans;
                continue;
            }
            for(int j = a[1]; j <= a[n]; j++)
                f[j] |= f[j - a[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}