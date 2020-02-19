#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN];
char tmp[MAXN];

int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", tmp);
        for (int j = 1; j <= m; ++j) {
            a[i][j] = tmp[j - 1] - '0';
            if (a[i][j] != 0) ans += 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += max(a[i][j] - a[i - 1][j], 0);
            ans += max(a[i][j] - a[i + 1][j], 0);
            ans += max(a[i][j] - a[i][j - 1], 0);
            ans += max(a[i][j] - a[i][j + 1], 0);
        }
    }
    printf("%d\n", ans);
    return 0;
}
