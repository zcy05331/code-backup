#include <bits/stdc++.h>

const int MaxN = 200010;

int cnt;
int a[MaxN];
int s[MaxN];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            s[++cnt] = 1;
        else
            ++s[cnt];
    }
    std::sort(s + 1, s + cnt + 1);
    int ans = 0;
    s[cnt + 1] = MaxN << 2;
    printf("%d\n", cnt);
    for (int i = 1; i <= s[1]; i++)
    {
        int tmp = i;
        int cur = i;
        int l = 2, r = cnt + 1;
        while (l <= cnt)
        {
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (s[mid] >= 2 * cur)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l > cnt)
                break;
            else
                tmp += 2 * cur;
            //printf("%d %d %d\n", i, l, r);
            l = l + 1, r = cnt + 1, cur <<= 1;
        }
        ans = std::max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}