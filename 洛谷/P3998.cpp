#include <bits/stdc++.h>

#define R register
#define ll long long
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

int n, m;
int a[MaxN], ans[MaxN];

std::map<std::pair<int, int>, int> map;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        char op;
        int x, y;
        std::cin >> op;
        if (op == '!')
            scanf("%d", &x), a[x]++;
        else if (op == '+')
            scanf("%d%d", &x, &y), map[mp(x, y)] = a[x], map[mp(y, x)] = a[y];
        else
        {
            scanf("%d%d", &x, &y);
            ans[y] += (a[x] - map[mp(x, y)]), ans[x] += (a[y] - map[mp(y, x)]);
            map.erase(mp(x, y)), map.erase(mp(y, x));
        }
    }
    for (std::map<std::pair<int, int>, int>::iterator it = map.begin(); it != map.end(); it++)
        ans[it->first.second] += (a[it->first.first] - it->second);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
