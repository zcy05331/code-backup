#include <bits/stdc++.h>
const int MaxN = 100010;
const int mod = 99999997;
int ans;
int c[MaxN];
long long tmp[MaxN];
int id1[MaxN], id2[MaxN];
long long a[MaxN], b[MaxN];
long long cmp1(int x, int y){return a[x] < a[y];}
long long cmp2(int x, int y){return b[x] < b[y];}
void Merge(int l, int r)
{
    if(l == r)
        return;
    else
    {
        int mid = (l + r) >> 1;
        Merge(l, mid);
        Merge(mid + 1, r);
        int t = l;
        int h1 = l, h2 = mid + 1, t1 = mid, t2 = r;
        while(t <= r)
        {
            if(h1 <= t1)
            {
                if(h2 <= t2)
                {
                    if(c[h1] <= c[h2])
                        tmp[t] = c[h1++];
                    else  
                        ans += t1 - h1 + 1, tmp[t] = c[h2++];
                }
                else tmp[t] = c[h1++];
            }
            else 
                tmp[t] = c[h2++];
            t++;
        }
        for(int i = l; i <= r; i++)
        {
            c[i] = tmp[i];
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), id1[i] = i;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]), id2[i] = i;
    std::sort(id1 + 1, id1 + n + 1, cmp1);
    std::sort(id2 + 1, id2 + n + 1, cmp2);
    for(int i = 1; i <= n; i++)
        c[id1[i]] = id2[i];
    Merge(1, n);
    printf("%d", ans % mod);
    return 0;
}