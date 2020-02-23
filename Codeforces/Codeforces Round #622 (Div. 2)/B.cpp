#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int getmax(int n, int x, int y){return std::min(n, std::max(1, x + y - n + 1));}
int getmin(int n, int x, int y){return std::min(n, x + y - 1);}

int main()
{   
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        printf("%d %d\n", getmax(n, x, y), getmin(n, x, y));
    }
    return 0;
}
