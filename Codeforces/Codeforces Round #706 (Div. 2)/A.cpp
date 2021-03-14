#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

int n, k;
char s[1001];

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int flag = -1;
        scanf("%d%d%s", &n, &k, s + 1);
        if (k == 0)
        {
            puts("YES");
            continue;
        }
        for (int i = 1; i <= n / 2; i++)
            if (s[i] != s[n - i + 1])
            {
                flag = i - 1;
                break;
            }
        if (flag >= k)
            puts("YES");
        else if (flag == -1 && (n - 1) / 2 >= k)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
