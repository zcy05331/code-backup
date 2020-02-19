#include <bits/stdc++.h>

#define ll long long

const int MaxN = 1000010;

int n;

int main()
{
    scanf("%d", &n);
    int tmp = n;
    ll now = 1;
    while(tmp != 1)
    {
        if(tmp == 3)
        {
            printf("%I64d %I64d %I64d", now, now, now * 3);
            return 0;
        }
        for(int i = 1; i <= (tmp + 1) / 2; i++)
            printf("%I64d ",now);
        tmp >>= 1;
        now <<= 1;
    }
    printf("%I64d", now);
    return 0;
}