#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n;
char s[MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    int T = read();
    while (T--)
    {
        int ans = 0;
        n = read(), scanf("%s", s + 1);
        for(int i = 2; i <= n; i++)
            if(s[i] == s[i - 1]) ++ans;
        printf("%d\n", (ans + 1) / 2);
    }
    return 0;
}
