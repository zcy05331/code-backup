#include <bits/stdc++.h>

const int MaxL = 2000 + 10;

int f[MaxL][MaxL];
char a[MaxL], b[MaxL];

int main()
{
    scanf("%s",a + 1);
    scanf("%s",b + 1);
    int lena = strlen(a + 1);
    int lenb = strlen(b + 1);
    for(int i = 0; i <= lena; i++)
        f[i][0] = i;
    for (int i = 0; i <= lenb; i++)
        f[0][i] = i;
    for(int i = 1; i <= lena; ++i)
    {
        for(int j = 1; j <= lenb; ++j)
        {
            f[i][j] = std::min(f[i][j - 1] + 1, f[i - 1][j] + 1);
            if(a[i] == b[j])f[i][j] = std::min(f[i - 1][j - 1], f[i][j]);
            else
                f[i][j] = std::min(f[i - 1][j - 1] + 1, f[i][j]);
        }
    }
    printf("%d", f[lena][lenb]);
    return 0;
}