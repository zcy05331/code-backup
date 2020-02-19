#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

std::string a, b, c, s;
int n, ans, used[100], num[100];

inline int to(char ch)
{
    return ch - 'A' + 1;
}

inline int check()
{
    int d = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[to(a[i])] + num[to(b[i])] + d) % n != num[to(c[i])])
            return 0;
        d = (num[to(a[i])] + num[to(b[i])] + d) / n;
    }
    return 1;
}

inline int pd()
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (num[to(a[i])] == -1 || num[to(b[i])] == -1 || num[to(c[i])] == -1)
            continue;
        if ((num[to(a[i])] + num[to(b[i])]) % n != num[to(c[i])])
            if ((num[to(a[i])] + num[to(b[i])] + 1) % n != num[to(c[i])])
                return 0;
    }
    return 1;
}

void dfs(int x)
{
    if (ans == 1)
        return;
    if (x > n)
    {
        if (check())
        {
            ans = 1;
            for (int i = 1; i <= n; i++)
                printf("%d ", num[i]);
        }
        return;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (used[i])
            continue;
        num[to(s[x - 1])] = i;
        if (pd())
        {
            used[i] = 1;
            dfs(x + 1);
            used[i] = 0;
        }
    }
    num[to(s[x - 1])] = -1;
}

int main()
{
    scanf("%d", &n);
    std::cin >> a >> b >> c;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!used[to(a[i])])
            s += a[i], used[to(a[i])] = 1;
        if (!used[to(b[i])])
            s += b[i], used[to(b[i])] = 1;
        if (!used[to(c[i])])
            s += c[i], used[to(c[i])] = 1;
    }
    memset(used, 0, sizeof(used));
    memset(num, -1, sizeof(num));
    dfs(1);
    return 0;
}
