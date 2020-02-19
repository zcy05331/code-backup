#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
const int MaxN = 500010;
std::string s, t;
int k, nums[MaxN], numt[MaxN], ans[MaxN], add[MaxN];
int main()
{
    scanf("%d", &k);
    std::cin >> s >> t;
    if (s == t)
    {
        std::cout << s;
        return 0;
    }
    for (int i = 1; i <= k; i++)
        nums[i] = s[i - 1] - 'a' + 1;
    for (int i = 1; i <= k; i++)
        numt[i] = t[i - 1] - 'a' + 1;
    for (int i = k; i >= 1; i--)
    {
        while (nums[i] > numt[i])
            numt[i] += 26, numt[i - 1]--;
        if ((numt[i] - nums[i]) % 2)
            add[i + 1] += 13;
        add[i] = (numt[i] - nums[i]) / 2;
    }
    for (int i = k; i >= 1; i--)
    {
        ans[i] += nums[i] + add[i];
        while (ans[i] > 26)
            ans[i - 1]++, ans[i] -= 26;
        while (ans[i] == 0)
            ans[i - 1]++, ans[i] += 26;
    }
    for (int i = 1; i <= k; i++)
        printf("%c", ans[i] + 'a' - 1);
    return 0;
}
