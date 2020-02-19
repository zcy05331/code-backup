# include <bits/stdc++.h>

int a[101];

int main()
{
    int n;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 2; i <= n - 1; i++)
    {
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1)
            ans++, a[i + 1] = 0;
    }
    printf("%d\n", ans);
    return 0;
}