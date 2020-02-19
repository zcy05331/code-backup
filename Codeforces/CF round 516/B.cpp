# include <bits/stdc++.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int a;
        scanf("%d", &a);
        int cnt = 0;
        while(a)
            cnt += a % 2, a /= 2;
        printf("%d\n", 1 << cnt);
    }
    return 0;
}