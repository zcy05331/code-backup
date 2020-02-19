#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 200010;
int n;
int a[MaxN];
std::vector<char> vec;
int main()
{
    scanf("%d", &n);
    int l = 1, r = n, now = -1;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (l > r)
            break;
        if (a[l] <= now && a[r] <= now)
            break;
        else if (a[l] <= now)
            vec.push_back('R'), now = a[r], --r;
        else if (a[r] <= now)
            vec.push_back('L'), now = a[l], ++l;
        else
        {
            if (a[l] < a[r])
                vec.push_back('L'), now = a[l], ++l;
            else
                vec.push_back('R'), now = a[r], --r;
        }
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++)
        printf("%c", vec[i]);
    return 0;
}
