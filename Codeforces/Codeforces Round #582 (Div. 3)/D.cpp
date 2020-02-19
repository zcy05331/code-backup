#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

std::map<int, int> map;
std::vector<int> vec[MaxN];

int n, k, ans = 0x3f3f3f3f;
int a[MaxN], m[MaxN], divt[MaxN], len[MaxN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), m[a[i]]++;
    for (int i = 0; i < 2e5; i++)
        if (m[i] >= k)
            return 0 * printf("0");
    for (int i = 1; i <= n; i++)
    {
        divt[i] = a[i];
        int cnt = 1;
        while (divt[i])
        {
            divt[i] /= 2;
            vec[divt[i]].push_back(cnt), ++cnt;
        }
        vec[0].push_back(cnt);
        len[i] = cnt;
    }
    for (int i = 0; i < 2e5; i++)
        std::sort(vec[i].begin(), vec[i].end());
    for (int i = 0; i < 2e5; i++)
    {
        int val = k - m[i], dmax = 0;
        for (int j = 0; j < vec[i].size() && val; j++)
            dmax += vec[i][j], --val;
        if (val <= 0)
            ans = std::min(ans, dmax);
    }
    printf("%d\n", ans);
    return 0;
}
