#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

char s[MaxN];
int n, q, cnt[MaxN][27];

int main()
{
    scanf("%s%d", s + 1, &q), n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 26; j++)
            cnt[i][j] = cnt[i - 1][j] + (s[i] == (j + 'a' - 1));
    }
    while (q--)
    {
        int l, r, num = 0;
        scanf("%d%d", &l, &r);
        if (l == r)
            puts("Yes");
        else if ((s[l] != s[r]))
            puts("Yes");
        else
        {
            for (int i = 1; i <= 26; i++)
                num += !!(cnt[r][i] - cnt[l - 1][i]);
            puts(num >= 3 ? "Yes" : "No");
        }
    }
    return 0;
}
