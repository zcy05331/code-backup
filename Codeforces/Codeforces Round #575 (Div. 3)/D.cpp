#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int n, k, ans = 0x3f3f3f3f;
std::string s, t, rgb = "RGB";

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        std::cin >> s;
        ans = 0x3f3f3f3f;
        for (int i = 0; i < 3; i++)
        {
            t.clear();
            for (int j = 0; j < k; j++)
                t += rgb[(i + j) % 3];
            for (int j = 0; j + k - 1 < n; j++)
            {
                int ret = 0;
                for (int l = 0; l < k; l++)
                    if (t[l] != s[j + l])
                        ret++;
                ans = cmin(ans, ret);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
