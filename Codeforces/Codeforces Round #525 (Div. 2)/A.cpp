# include <bits/stdc++.h>

int main()
{
    int x;
    scanf("%d", &x);
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= x; j++)
            if((i % j == 0) && (j * i > x) && ((i / j) < x))
                return 0 * printf("%d %d\n", i, j);
    printf("-1");
    return 0;
}