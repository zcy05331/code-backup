#include <bits/stdc++.h>

int n, k;
int a[200010], ans[200010];
int s[200010];
std::queue<int> st;

int check(int x)
{
    while(!st.empty())
        st.pop();
    for(int i = 1; i <= 200000; i++)
        for(int j = s[i] / x; j; j--)
            st.push(i);
    if(st.size() >= k)
    {
        for(int i = 1; i <= k; i++)
            ans[i] = st.front(), st.pop();
        return true;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), s[a[i]]++;
    int l = 0, r = 200001;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    for (int i = 1; i <= k; i++)
        printf("%d ", ans[i]);
    return 0;
}