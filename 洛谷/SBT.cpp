#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100100;
int M;
struct Size_Blanced_Tree
{
    int rt, NodeCnt;
    int key[N], s[N], left[N], right[N];
    void clear()
    {
        rt = 0, NodeCnt = 0;
        memset(key, 0, sizeof(key));
        memset(s, 0, sizeof(s));
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
    }
    void zig(int &p)
    {
        int k = right[p];
        right[p] = left[k];
        left[k] = p;
        s[k] = s[p];
        s[p] = s[left[p]] + s[right[p]] + 1;
        p = k;
    }
    void zag(int &p)
    {
        int k = left[p];
        left[p] = right[k];
        right[k] = p;
        s[k] = s[p];
        s[p] = s[left[p]] + s[right[p]] + 1;
        p = k;
    }
    void maintain(int &p, bool flag)
    {
        if (!flag)
        {
            if (s[left[left[p]]] > s[right[p]])
                zag(p);
            else
            {
                if (s[right[left[p]]] > s[right[p]])
                {
                    zig(left[p]);
                    zag(p);
                }
                else
                    return;
            }
        }
        else
        {
            if (s[right[right[p]]] > s[left[p]])
                zig(p);
            else
            {
                if (s[left[right[p]]] > s[left[p]])
                {
                    zag(right[p]);
                    zig(p);
                }
                else
                    return;
            }
        }
        maintain(left[p], false);
        maintain(right[p], true);
        maintain(p, true);
        maintain(p, false);
    }
    void insert(int &p, int x)
    {
        if (!p)
        {
            p = ++NodeCnt;
            key[p] = x;
            s[p] = 1;
            return;
        }
        s[p]++;
        if (x < key[p])
            insert(left[p], x);
        else
            insert(right[p], x);
        maintain(p, x >= key[p]);
    }
    int erase(int &p, int x)
    {
        s[p]--;
        int tmp;
        if (x == key[p] || (x < key[p] && !left[p]) || (x > key[p] && !right[p]))
        {
            tmp = key[p];
            if (!left[p] || !right[p])
                p = left[p] + right[p];
            else
                key[p] = erase(left[p], key[p] + 1);
            return tmp;
        }
        if (x < key[p])
            tmp = erase(left[p], x);
        else
            tmp = erase(right[p], x);
        return tmp;
    }
    int rank(int &p, int x)
    {
        if (!p)
            return 1;
        int tmp = 0;
        if (x <= key[p])
            tmp = rank(left[p], x);
        else
            tmp = s[left[p]] + 1 + rank(right[p], x);
        return tmp;
    }
    int select(int &p, int x)
    {
        if (x == s[left[p]] + 1)
            return key[p];
        if (x <= s[left[p]])
            return select(left[p], x);
        else
            return select(right[p], x - 1 - s[left[p]]);
    }
    int pred(int &p, int x)
    {
        if (!p)
            return x;
        int tmp;
        if (x <= key[p])
            tmp = pred(left[p], x);
        else
        {
            tmp = pred(right[p], x);
            if (tmp == x)
                tmp = key[p];
        }
        return tmp;
    }
    int succ(int &p, int x)
    {
        if (!p)
            return x;
        int tmp;
        if (x >= key[p])
            tmp = succ(right[p], x);
        else
        {
            tmp = succ(left[p], x);
            if (tmp == x)
                tmp = key[p];
        }
        return tmp;
    }
} T;
int main()
{
    scanf("%d", &M);
    T.clear();
    int &rt = T.rt = 0;
    while (M--)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        if (opt == 1)
            T.insert(rt, x);
        else if (opt == 2)
            T.erase(rt, x);
        else if (opt == 3)
            printf("%d\n", T.rank(rt, x));
        else if (opt == 4)
            printf("%d\n", T.select(rt, x));
        else if (opt == 5)
            printf("%d\n", T.pred(rt, x));
        else if (opt == 6)
            printf("%d\n", T.succ(rt, x));
    }
    return 0;
}