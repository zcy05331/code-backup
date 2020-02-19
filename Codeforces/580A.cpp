#include <bits/stdc++.h>

const int MaxN = 100010;

int n;
int a[MaxN];
int f[MaxN];
int ans;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 1;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++)
    {
        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(f[mid] <= a[i])
                l = mid;
            else r = mid - 1;
        }
        f[l + 1] = f[l + 1] > a[i] ? a[i] : f[l + 1];
        ans = std::max(ans, l + 1);
        //for(int j = 1; j <= n; j++)
        //    printf("%d ", f[j]);
       // puts("");
    }
    //for(int i = 1; i <= n; i++)
    //    printf("%d\n", f[i]);
    printf("%d\n", ans);
    return 0;
}