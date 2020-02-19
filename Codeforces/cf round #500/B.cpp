#include <bits/stdc++.h>

const int MaxN = 100010;
int a[MaxN] = {};
int m[MaxN] = {}, m1[MaxN] = {};
int n,x;



int main()
{

    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(m[a[i]])
        {
            printf("0");
            return 0;
        }
        m[ a[i] ]++;
        m1[a[i] & x]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(m[a[i] & x] == 1 && (a[i] & x) != a[i] || m[a[i] & x] > 1)
        {
            puts("1");
            return 0;
        }
    }
    for (int i = 0; i <= 100000; i++)
    {
        if(m1[i] >= 2)
        {
            puts("2");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}