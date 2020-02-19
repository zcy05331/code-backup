#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
const int MaxN = 200010;
int n;
int sum[MaxN], a[MaxN];
std::map<int, int> id;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
        id[sum[i]] = i;
    }
    std::sort(sum, sum + n);
    for (int i = 0; i < n; i++)
        a[id[sum[i]]] = i + 1;
    for (int i = 1; i < n; i++)
        if (sum[i] != sum[i - 1] + 1)
            return puts("-1") * 0;
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    return 0;
}
