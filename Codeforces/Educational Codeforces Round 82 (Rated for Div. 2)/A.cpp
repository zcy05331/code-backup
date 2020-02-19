#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int n;
char s[1001];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s + 1), n = strlen(s + 1);
        int l = 0, r = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '1')
            {
                r = i, cnt++;
                if (!l)
                    l = i;
            }
        }
        if (cnt)
            printf("%d\n", (r - l + 1) - cnt);
        else printf("0\n");
    }
    return 0;
}
