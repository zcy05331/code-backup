#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e2 + 10;

std::vector<int> vec;
int n, m, g[MaxN][MaxN];

int f(int x) { return x * (x - 1) * (x - 2) / 6; }

void find(int x)
{
    if(x <= 0) return; 
    for(int i = 500; i >= 3; i--)
    {
        if(f(i) <= x)
        {
            vec.push_back(i), find(x - f(i));
            return;
        }
    }
}

int main()
{   
    int now = 0;
    scanf("%d", &n), find(n);
    for(auto x : vec)
    {
        for(int i = 1; i <= x; i++)
        {
            for(int j = i + 1; j <= x; j++)
                g[now + i][now + j] = 1;
        }
        now += x;
    }
    printf("%d\n", now);
    for(int i = 1; i <= now; i++)
    {
        for(int j = 1; i + j <= now; j++)
            printf("%d ", g[i][i + j]);
        puts("");
    }
    return 0;
}
