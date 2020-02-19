#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e3 + 10;

int n, m, q;
char ch[MaxN];
std::bitset<MaxN> t, t1, tmp, s[MaxN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ch + 1);
        for (int j = 1; j <= m; j++)
            if (ch[j] - '0')
                s[i][j] = 1;
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s", ch + 1), t.reset();
        for (int i = 1; i <= m; i++)
        {
            if (ch[i] == '_')
                t[i] = 1;
            else
                t1[i] = ((ch[i] == '1') ? 1 : 0);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            tmp = (s[i] ^ t1);
            if ((tmp & t) == tmp)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
