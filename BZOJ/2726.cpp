#include <bits/stdc++.h>

const int MaxN = 500010;

long long f[MaxN];
long long sumt[MaxN], sumc[MaxN];

int dq[MaxN];
int l = 1, r = 1;

int bs(int i, int k)
{
    if(l == r)
        return dq[l];
    int L = l, R = r;
    while(L < R)
    {
        int mid = (L + R) >> 1;
        if((f[dq[mid + 1]] - f[dq[mid]]) <= k * (sumc[dq[mid + 1]] - sumc[dq[mid]]))
            L = mid + 1;
        else R = mid;
    }
    return dq[L];
}

int main()
{
    long long n, s;
    scanf("%lld%lld", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        int t, c;
        scanf("%d%d", &t, &c);
        sumt[i] = sumt[i - 1] + t;
        sumc[i] = sumc[i - 1] + c;
    }
    l = r = 1;
    dq[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int p = bs(i, s + sumt[i]); 
        f[i] = f[p] - (s + sumt[i]) * sumc[p] + sumt[i] * sumc[i] + s * sumc[n];
        while (l < r && (f[dq[r]] - f[dq[r - 1]]) * (sumc[i] - sumc[dq[r]]) >= (f[i] - f[dq[r]]) * (sumc[dq[r]] - sumc[dq[r - 1]]))
            r--;
        dq[++r] = i;
    }
    printf("%lld", f[n]);
    return 0;
}