#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#define MN 300005
#define MM 15000005
using namespace std;
typedef long long ll;
typedef double db;
int n, tt, ans = 300000, a[MN], lst[MM], pr[MM], cnt[MM], st[MN];
bool p[MM];
map<int, bool> used;
int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
int main()
{
    for (int i = 2; i <= 15000000; i++)
    {
        if (!p[i])
            pr[++tt] = i, lst[i] = i;
        for (int j = 1; j <= tt; j++)
        {
            if (1ll * i * pr[j] > 15000000)
                break;
            p[i * pr[j]] = 1, lst[i * pr[j]] = pr[j];
            if (i % pr[j] == 0)
                break;
        }
    }
    scanf("%d", &n);
    int tt = 0, maxn = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), tt += a[i] == a[1];
    if (tt == n)
        return 0 * puts("-1");
    int tmp = a[1];
    for (int i = 2; i <= n; i++)
        tmp = gcd(tmp, a[i]);
    for (int i = 1; i <= n; i++)
        a[i] /= tmp;
    for (int i = 1; i <= n; i++)
    {
        int top = 0;
        int tmp = a[i];
        while (tmp != 1)
        {
            if (!used[lst[tmp]])
                cnt[lst[tmp]]++, st[++top] = lst[tmp], used[lst[tmp]] = 1;
            tmp /= lst[tmp];
        }
        for (int j = 1; j <= top; j++)
            used[st[j]] = 0;
    }
    for (int i = 2; i <= 15000000; i++)
        ans = min(ans, n - cnt[i]);
    printf("%d\n", ans);
}