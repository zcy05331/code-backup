#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
const int MaxN = 2e3 + 10;
int n, od, ev;
int a[MaxN], odd[MaxN], even[MaxN];
int cmp(int a, int b)
{
    return a > b;
}
inline int solve1()
{
    int ret = 0;
    int cnt = 1;
    ret = odd[1];
    while (cnt <= od && cnt <= ev)
    {
        ret += odd[cnt + 1] + even[cnt];
        ++cnt;
    }
    return ret;
}
inline int solve2()
{
    int ret = 0;
    int cnt = 1;
    ret = even[1];
    while (cnt <= od && cnt <= ev)
    {
        ret += odd[cnt] + even[cnt + 1];
        ++cnt;
    }
    return ret;
}
int main()
{
    int sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum += a[i];
    std::sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2)
            odd[++od] = a[i];
        else
            even[++ev] = a[i];
    }
    int ans1 = solve1();
    int ans2 = solve2();
    printf("%d\n", sum - cmax(ans1, ans2));
    return 0;
}
