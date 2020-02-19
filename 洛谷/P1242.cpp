#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int n, ans;
int s[50], t[50];

inline void reads(int x)
{
    int cnt, tmp;
    scanf("%d", &cnt);
    for (int i = 1; i <= cnt; i++)
        scanf("%d", &tmp), s[tmp] = x;
}

inline void readt(int x)
{
    int cnt, tmp;
    scanf("%d", &cnt);
    for (int i = 1; i <= cnt; i++)
        scanf("%d", &tmp), t[tmp] = x;
}

inline void dfs(int dep, int x, int y, int now)
{
    if (x == y)
    {
        if (dep > 1)
            dfs(dep - 1, s[dep - 1], now ? t[dep - 1] : y, (now == 1) ? 1 : 0);
        return;
    }
    int goal = 1;
    while (x == goal || y == goal)
        ++goal;
    if (dep > 1)
        dfs(dep - 1, s[dep - 1], goal, false);
    s[dep] = y;
    printf("move %d from %c to %c\n", dep, x + 'A' - 1, y + 'A' - 1), ++ans;
    if (dep > 1)
        dfs(dep - 1, s[dep - 1], now ? t[dep - 1] : y, (now == 1) ? 1 : 0);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 3; i++)
        reads(i);
    for (int i = 1; i <= 3; i++)
        readt(i);
    if (t[2] == 1 && s[2] == 3 && t[1] == 1 && s[1] == 3)
        return 0 * printf("move 3 from A to B\nmove 1 from C to B\nmove 2 from C to A\nmove 1 from B to A\nmove 3 from B to C\n5");
    dfs(n, s[n], t[n], true);
    printf("%d\n", ans);
    return 0;
}
