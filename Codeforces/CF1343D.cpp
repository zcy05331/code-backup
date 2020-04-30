#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 4e5 + 10;
const int inf = 0x3f3f3f3f;

int n, m, k, ans;
int a[MaxN], pre[MaxN];
std::unordered_map<int, int> cnt;

void init()
{
    ans = inf, cnt.clear();
    for (int i = 0; i <= k * 2 + 5; i++) pre[i] = 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init(), scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n / 2; i++)
        {
            cnt[a[i] + a[n - i + 1]]++;
            pre[std::min(a[i], a[n - i + 1]) + 1]++;
            pre[std::max(a[i], a[n - i + 1]) + k + 1]--;
        }
        for (int i = 1; i <= 2 * k; i++)
            pre[i] += pre[i - 1];
        for (int i = 2; i <= 2 * k; i++)
        {
            int num = 2 * ((n / 2) - pre[i]) + (pre[i] - cnt[i]);
            ans = std::min(ans, num);
        }
        printf("%d\n", ans);
    }
    return 0;
}
