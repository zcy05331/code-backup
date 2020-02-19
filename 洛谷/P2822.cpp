# include <bits/stdc++.h>

const int MaxN = 2010;

int k;
int n, m;

int C[MaxN][MaxN];
int s[MaxN][MaxN];
void prework()
{
    C[1][1] = 1;
    for(int i = 0; i <= 2000; i++)
        C[i][0] = 1;
    for(int i = 2; i <= 2000; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % k;
        }
    }
    for(int i = 2; i <= 2000; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if(C[i][j] == 0)
                s[i][j]++;
        }
        s[i][i + 1] = s[i][i];
    }
}
int main()
{
    int T;
    scanf("%d%d", &T, &k);
    prework();
    for(int i = 1; i <= T; i++)
    {
        scanf("%d%d", &n, &m);
        if(m > n)
            m = n;
        printf("%d\n", s[n][m]);
    }
    return 0;
}