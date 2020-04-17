#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;

int read()
{
    int out = 0;
    char c;
    while (!isdigit(c = getchar()))
        ;
    for (; isdigit(c); c = getchar())
        out = out * 10 + c - '0';
    return out;
}

const int N = 1000010;

struct Node
{
    int val, ch[2], d;
} t[N];

int &rs(int x);
int merge(int x, int y);

int find(int x);

int n, m, f[N];
bool kill[N];
char op[10];

int main()
{
    int i, x, y;

    n = read();

    for (i = 1; i <= n; ++i)
    {
        t[i].val = read();
        f[i] = i;
    }

    m = read();

    while (m--)
    {
        scanf("%s", op);
        if (op[0] == 'M')
        {
            x = read();
            y = read();
            if (kill[x] || kill[y] || find(x) == find(y)) continue;
            f[find(x)] = f[find(y)] = merge(find(x), find(y));
        }
        else
        {
            x = read();
            if (!kill[x])
            {
                x = find(x);
                kill[x] = true;
                f[x] = f[t[x].ch[0]] = f[t[x].ch[1]] = merge(t[x].ch[0], t[x].ch[1]);
                // 由于堆中的点会 find 到 x，所以 f[x] 也要修改
                printf("%d\n", t[x].val);
            }
            else
                puts("0");
        }
    }

    return 0;
}

int merge(int x, int y)
{
    if (!x || !y) return x | y;          // 若一个堆为空则返回另一个堆
    if (t[x].val > t[y].val) swap(x, y); // 取值较小的作为根
    t[x].rs = merge(t[x].rs, y);         // 递归合并右儿子与另一个堆
    if (t[t[x].rs].d > t[t[x].ls].d)
        swap(t[x].ls, t[x].rs); // 若不满足左偏性质则交换左右儿子
    t[x].d = t[t[x].rs].d + 1;  // 更新dist
    return x;
}

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }