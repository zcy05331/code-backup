#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e3 + 10;

int n, m, k, a[MaxN];

int main()
{   
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans = 0, tmp = std::max(0, m - k - 1);
        if(tmp)
        {
            int x = std::min(k, m - 1);
            for(int i = 0; i <= x; i++)
            {
                int l = i + 1, r = n - k + i, minn = 1e9 + 10;
                for(int j = 0; j <= tmp; j++)
                    minn = std::min(minn, std::max(a[l + j], a[r - tmp + j]));
                ans = std::max(ans, minn);
            }
            printf("%d\n", ans);
        }
        else 
        {
            for(int i = 1; i <= n; i++)
                if(i + m > n || m >= i)
                    ans = std::max(ans, a[i]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
