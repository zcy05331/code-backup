#include <bits/stdc++.h>
using namespace std;
const int point[] = {0, 6, 7, 8, 9, 10};
struct line
{
    int cnt, id;
} l[15];
int a[10][10], ans, row[10][10], col[10][10], square[10][10];

int cmp(line a, line b) { return a.cnt < b.cnt; }
int getsquare(int x, int y) { return ((x - 1) / 3) * 3 + (y - 1) / 3 + 1; }

int check()
{
    int tmp = 0;
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            tmp += a[i][j] * point[std::min(std::min(i, 10 - i), std::min(j, 10 - j))];
    ans = std::max(ans, tmp);
    // printf("time = %d\n", clock());
}

int dfs(int x, int y, int now)
{
    if (now == 10)
        return check();
    if (y == 10)
        return dfs(l[now + 1].id, 1, now + 1);
    if(a[x][y])
        return dfs(x, y + 1, now);
    if (!a[x][y])
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (row[x][i] == 0 && col[y][i] == 0 && square[getsquare(x, y)][i] == 0)
            {
                row[x][i] = 1, col[y][i] = 1, square[getsquare(x, y)][i] = 1;
                a[x][y] = i;
                dfs(x, y + 1, now);
                a[x][y] = 0;
                row[x][i] = 0, col[y][i] = 0, square[getsquare(x, y)][i] = 0;
            }
        }
    }
}

int main()
{
    int tmp = 0;
    for (int i = 1; i <= 9; ++i)
    {
        tmp = 0;
        for (int j = 1; j <= 9; ++j)
        {
            scanf("%d", &a[i][j]);
            tmp += bool(a[i][j] != 0);
            row[i][a[i][j]] = col[j][a[i][j]] = square[getsquare(i, j)][a[i][j]] = 1;
        }
        l[i].id = i, l[i].cnt = tmp;
    }
    std::sort(l + 1, l + 9 + 1, cmp);
    printf("time = %d\n", clock());
    dfs(l[1].id, 1, 1);
    printf("%d\n", (ans == 0) ? -1 : ans);
    printf("time = %d\n", clock());
    return 0;
}