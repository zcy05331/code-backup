#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define check(ex, ey) ((ex > 0) && (ex <= n) && (ey > 0) && (ey <= m))
#define mp(i, j) std::make_pair(i, j)

const int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};

char a[410][410], b[410][410];
std::string s;
int n, m, q, x, y, now, lastx, lasty;
std::deque<std::pair<int, int>> vec;

int get(char s)
{
    if (s == 'S')
        return 1;
    if (s == 'D')
        return 2;
    if (s == 'W')
        return 3;
    if (s == 'A')
        return 4;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '@')
                x = lastx = i, y = lasty = j, a[i][j] = '.', vec.push_back(mp(i, j));
    }
    std::cin >> s, q = s.length();
    for (int i = 0; i < q; i++)
    {
        int pos = get(s[i]);
        x += dx[pos], y += dy[pos];
        if (!check(x, y))
            return 0 * printf("GG");
        if (a[x][y] != 'o')
            vec.pop_front();
        else
            a[x][y] = '.';
        vec.push_back(mp(x, y));
    }
    memcpy(b, a, sizeof(a));
    while (!vec.empty())
        b[vec.front().first][vec.front().second] = 'X', vec.pop_front();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == x && j == y)
                printf("@");
            else
                printf("%c", b[i][j]);
        }
        puts("");
    }
    return 0;
}
