#include <bits/stdc++.h>

#define ll long long

const int MaxN = 2010;

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int n, m;

std::string s[MaxN], a[MaxN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        std::cin >> s[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            a[i] += '.';
    }
        
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            bool flag = true;
            for(int k = 0; k < 8; k++)
                if(s[i + dx[k]][j + dy[k]] != '#')
                    flag = 0;
            if(flag)
            {
                for(int k = 0; k < 8; k++)
                    a[i + dx[k]][j + dy[k]] = '#';
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != s[i][j])
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}