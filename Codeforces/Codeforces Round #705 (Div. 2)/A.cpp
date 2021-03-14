#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 1e5 + 10;

int n, k, cnt[27];
char s[MaxN], t[MaxN];

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int ans = 0, spos = 0;
        scanf("%d%d%s", &n, &k, s + 1);
        if (n % k)
        {
            printf("-1\n");
            continue;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
            cnt[s[i] - 'a']++, t[i] = 0;
        memset(t, 0, n + 10);
        for (int i = 0; i < 26; i++)
            if (cnt[i] % k) ans = -1;
        if (~ans)
        {
            printf("%s\n", s + 1);
            continue;
        }
        ans = 1, spos = s[1] + 1;
        for (int i = n; i; i--)
        {
            if (s[i] == 'z') continue;
            int num = 0;
            cnt[s[i] - 'a']--;
            for (int l = s[i] - 'a' + 1; l < 26; l++)
            {
                cnt[l]++, num = 0;
                for (int j = 0; j < 26; j++)
                    num += k * ((cnt[j] / k) + ((cnt[j] % k) != 0)) - cnt[j];
                if (num <= n - i)
                {
                    ans = i, spos = l;
                    break;
                }
                cnt[l]--;
            }
            if (ans == i) break;
        }
        // meow("$ %d %c\n", ans, spos + 'a') ;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i < ans; i++)
            t[i] = s[i], cnt[t[i] - 'a']++;
        t[ans] = spos + 'a', cnt[t[ans] - 'a']++;
        int pos = ans + 1, sum = 0;
        for (int i = 0; i < 26; i++)
            cnt[i] = k * ((cnt[i] / k) + ((cnt[i] % k) != 0)) - cnt[i], sum += cnt[i];
        while (sum + ans < n)
            sum += k, cnt[0] += k;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < cnt[i]; j++)
                t[pos] = i + 'a', ++pos;
        printf("%s\n", t + 1);
    }
    return 0;
}
