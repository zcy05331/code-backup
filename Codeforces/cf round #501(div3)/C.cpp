#include <bits/stdc++.h>
#define ll I64

const int MaxN = 100010;
int m;
int n;
int l, r;
long long sum,tmp;
int a[MaxN];

int main()
{
    scanf("%d%d", &n, &m);
    for(register int i = 1; i <= n; ++i )
    {
        scanf("%d%d", &l, &r);
        sum += l;
        tmp += r;
        a[i] = r - l;
    }
    if (sum <= m)
    {
        puts("0");
        return 0;
    }
    if (tmp > m)
    {
        puts("-1");
        return 0;
    }
    std::sort(a + 1, a + n + 1);
    for(register int i = 1; i <= n; ++i)
    {
        sum += a[i];
        if(sum <= m)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}