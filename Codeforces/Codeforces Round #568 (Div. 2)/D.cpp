#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

int n, cnt;
int s[MaxN];
std::map<int, int> m;
std::pair<int, int> a[MaxN];

inline void add(int x)
{
    m[x]++;
    if (m[x] == 1)
        ++cnt;
}

inline void del(int x)
{
    m[x]--;
    if (m[x] == 0)
        --cnt;
}

int main()
{
    scanf("%d", &n);
    if (n <= 3)
        return 0 * printf("1");
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first), a[i].second = i;
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
        s[i] = a[i + 1].first - a[i].first, add(s[i]);
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            del(s[1]);
            if (cnt == 1)
                return 0 * printf("%d\n", a[i].second);
            add(s[1]);
        }
        else if (i == n)
        {
            del(s[i - 1]);
            if (cnt == 1)
                return 0 * printf("%d\n", a[i].second);
            add(s[i - 1]);
        }
        else
        {
            del(s[i - 1]);
            del(s[i]);
            add(s[i - 1] + s[i]);
            if (cnt == 1)
                return 0 * printf("%d\n", a[i].second);
            del(s[i - 1] + s[i]);
            add(s[i - 1]);
            add(s[i]);
        }
    }
    printf("-1");
    return 0;
}
