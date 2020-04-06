#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define re register
using namespace std;

namespace io
{
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;
inline char gc() { return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++); }
inline void flush()
{
    fwrite(obuf, 1, oS - obuf, stdout);
    oS = obuf;
}
inline void putc(char x)
{
    *oS++ = x;
    if (oS == oT) flush();
}
template <class I>
inline void read(I &x)
{
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc())
        if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc())
        x = x * 10 + (c & 15);
    x *= f;
}
template <class I>
inline void print(I x)
{
    if (!x) putc('0');
    if (x < 0) putc('-'), x = -x;
    while (x)
        qu[++qr] = x % 10 + '0', x /= 10;
    while (qr)
        putc(qu[qr--]);
}
} // namespace io
using io::gc;
using io::print;
using io::putc;
using io::read;

const int MAXN = 600010 + 10;

int trie[MAXN * 24][2], latest[MAXN * 24];
int s[MAXN], root[MAXN];
int n, m, tot;

inline void insert(int i, int k, int p, int q)
{
    if (k < 0)
    {
        latest[q] = i;
        return;
    }
    int c = s[i] >> k & 1;
    if (p) trie[q][c ^ 1] = trie[p][c ^ 1];
    trie[q][c] = ++tot;
    insert(i, k - 1, trie[p][c], trie[q][c]);
    latest[q] = max(latest[trie[q][0]], latest[trie[q][1]]);
}

inline int query(int now, int val, int k, int L)
{
    if (k < 0) return s[latest[now]] ^ val;
    int c = val >> k & 1;
    if (latest[trie[now][c ^ 1]] >= L)
        return query(trie[now][c ^ 1], val, k - 1, L);
    else
        return query(trie[now][c], val, k - 1, L);
}

int main()
{
    read(n), read(m), latest[0] = -1, root[0] = ++tot;
    insert(0, 23, 0, root[0]);
    for (re int i = 1, x; i <= n; ++i)
    {
        read(x), s[i] = s[i - 1] ^ x, root[i] = ++tot;
        insert(i, 23, root[i - 1], root[i]);
    }
    for (re int i = 1, x, l, r; i <= m; ++i)
    {
        char op = gc();
        while (!isalpha(op))
            op = gc();
        if (op == 'A')
        {
            read(x), root[++n] = ++tot, s[n] = s[n - 1] ^ x;
            insert(n, 23, root[n - 1], root[n]);
        }
        else
        {
            read(l), read(r), read(x);
            print(query(root[r - 1], s[n] ^ x, 23, l - 1)), putc('\n');
        }
    }
    io::flush();
    return 0;
}