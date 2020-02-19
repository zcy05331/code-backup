#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

int n;
char a[MaxN], b[MaxN], c[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int flag = 1;
        scanf("%s%s%s", a + 1, b + 1, c + 1), n = strlen(a + 1);
        for (int i = 1; i <= n; i++)
            flag &= ((a[i] == c[i]) || (b[i] == c[i]));
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
