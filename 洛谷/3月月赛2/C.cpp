#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
int p, k;
int main()
{   
    scanf("%d%d", &p, &k);
    if(k == 1)
    {
        puts("YES");
        for(int i = 0; i < p; i++)
            printf("%d ", i);
    }
    if(p == 2)
    {
        int cnt = 1;
        for(int i = 1; i <= k; i++)
            cnt *= p;
        puts("YES");
        for(int i = 0; i < cnt; i++)
            for(int j = i + 1; j < cnt; j++)
                printf("%d %d\n", i, j);
    }
    return 0;
}
