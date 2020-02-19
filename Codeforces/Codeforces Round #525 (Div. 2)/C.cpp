# include <bits/stdc++.h>

int a[2010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]); 
    printf("%d\n", n + 1);
    printf("1 %d %d\n", n, 899999);
    for(int i = 1; i <= n; i++)
    {
        a[i] += 899999;
        printf("2 %d %d\n", i, (a[i] - i + 1));
        a[i] %= (a[i] - i + 1);
    }
    return 0;
}