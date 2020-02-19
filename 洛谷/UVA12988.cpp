#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[10][10];
int row[9], col[9], grid[9], cnt[512], num[512], tot;

inline int g(int x, int y)
{
    return ((x / 2) * 2) + (y / 2);
}

inline void flip(int x, int y, int z)
{
    row[x] ^= 1 << z;
    col[y] ^= 1 << z;
    grid[g(x, y)] ^= 1 << z;
}

bool dfs(int now)
{
    if (now == 0)
        return 1;
    int temp = 10, x, y;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (str[i][j] != '*')
                continue;
            int val = row[i] & col[j] & grid[g(i, j)];
            if (!val)
                return 0;
            if (cnt[val] < temp)
            {
                temp = cnt[val];
                x = i, y = j;
            }
        }
    int val = row[x] & col[y] & grid[g(x, y)];
    for (; val; val -= val & -val)
    {
        int z = num[val & -val];
        str[x][y] = '1' + z;
        flip(x, y, z);
        if (dfs(now - 1))
            return 1;
        flip(x, y, z);
        str[x][y] = '*';
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 1 << 4; i++)
        for (int j = i; j; j -= j & -j)
            cnt[i]++;
    for (int i = 0; i < 4; i++)
        num[1 << i] = i;
    char s[100];
    int T;
    scanf("%d", &T);
    int totot = 0;
    while (T--)
    {
        ++totot;
        for (int i = 0; i < 4; i++)
        {
            std::cin >> s;
            for (int j = 0; j < 4; j++)
                str[i][j] = s[j];
        }
        for (int i = 0; i < 4; i++)
            row[i] = col[i] = grid[i] = (1 << 4) - 1;
        tot = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (str[i][j] != '*')
                    flip(i, j, str[i][j] - '1');
                else
                    tot++;
        dfs(tot);
        printf("Case #%d:\n", totot);
        for (int i = 0; i < 4; i++)
            printf("%s\n", str[i]);
    }
    return 0;
}
