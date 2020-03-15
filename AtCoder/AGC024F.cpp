#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 21;
const int MaxM = (1 << 21) + 10;

char s[MaxM];
int n, k, lim, f[MaxN][MaxM];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; i++)
    {
        lim = (1 << i), scanf("%s", s);
        for (int j = 0; j < lim; j++)
            if(s[j] == '1')
                f[i][j | lim] = 1;
    }
    for(int i = n; i; i--)
    {
        for(int j = i; j <= n; j++)
        {
            lim = (1 << j);
            for(int k = 0; k < lim; k++)
            {
                int tmp = f[i][k | lim], p = - 1, q = -1;
                if(!tmp) continue;
                for(int t = i - 1; ~t; t--)
                    if(k & (1 << t)) {p = t; break;}
                for(int t = i - 1; ~t; t--)
                    if((k & (1 << t)) == 0) {q = t; break;}
                f[0][(k + lim) >> i] += tmp;
                if (~p) f[p][(1 << (j - i + p + 1)) | (((1 << p) - 1) & k) | ((((k >> i) << 1) | 1) << p)] += tmp;
                if (~q) f[q][(1 << (j - i + q + 1)) | (((1 << q) - 1) & k) | ((((k >> i) << 1)) << q)] += tmp;
            }
        }
    }
    for(int i = n; ~i; i--)
    {
        lim = (1 << i);
        for(int j = 0; j < lim; j++)
        {
            if(f[0][j | (1 << i)] >= k)
            {
                for(int l = i - 1; ~l; l--)
                    putchar('0' + (!!(j & (1 << l))));
                return 0;
            }
        }
    }
    return 0;
}
