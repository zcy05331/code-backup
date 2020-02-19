#include <cstring>
#include <cstdio>
#include <bitset>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int a[10000];
int n, ans;
std::bitset<10001> bit;

inline int fast_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a);
        a = (a * a);
        b >>= 1;
    }
    return ans;
}

void dfs(int m, int dep)
{
    if (ans)
        return;
    if (dep > m)
    {
        if (a[m] == n)
            ans = 1;
        return;
    }
    bit.reset();
    for (int i = dep - 1; i >= 1; --i)
    {
        for (int j = i; j >= 1; --j)
        {
            if (bit[a[i] + a[j]] || (a[i] + a[j] <= a[dep - 1]))
                continue;
            a[dep] = a[i] + a[j];
            bit[a[i] + a[j]] = 1;
            if (fast_pow(2, m - dep) * a[dep] >= n)
                dfs(m, dep + 1);
            if (ans)
                return;
            a[dep] = 0;
        }
    }
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        ans = 0;
        memset(a, 0, sizeof(a));
        a[1] = 1;
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        for (int i = 2; i <= 20; i++)
        {
            dfs(i, 2);
            if (ans)
            {
                for (int j = 1; j <= i; j++)
                    printf("%d", a[j]), printf((j == i) ? "" : " ");
                puts("");
                break;
            }
        }
    }
    return 0;
}
