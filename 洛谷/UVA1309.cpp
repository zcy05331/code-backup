#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

typedef std::bitset<20> bit;

int a[20][20];
bit used[20][20];
bit r[20], c[20], grid[20];

inline int g(int x, int y) { return ((x - 1) / 4) * 4 + ((y - 1) / 4) + 1; }

int main()
{
    std::string s;
    for (int i = 1; i <= 16; i++)
    {
        std::cin >> s;
        for (int j = 1; j <= 16; j++)
        {
            if (s[j - 1] == '-')
                a[i][j] = 0;
            else
            {
                a[i][j] = s[j - 1] - 'A' + 1;
                r[i][a[i][j]] = 1;
                c[j][a[i][j]] = 1;
                grid[g(i, j)][a[i][j]] = 1;
            }
        }
    }
    for (int i = 1; i <= 16; i++)
        r[i].flip(), c[i].flip(), grid[i].flip();
    for (int i = 1; i <= 16; i++)
    {
        for (int j = 1; j <= 16; i++)
            if (a[i][j] == 0)
                used[i][j] = (r[i] & c[j] & grid[g(i, j)]);
    }
    return 0;
}
