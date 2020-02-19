// powered by c++11
// by Isaunoya
#include <bits/stdc++.h>
#define rep(i, x, y) for (register int i = (x); i <= (y); ++i)
#define Rep(i, x, y) for (register int i = (x); i >= (y); --i)
using namespace std;
using db = double;
using ll = long long;
using uint = unsigned int;
#define int long long
using pii = pair<int, int>;
#define ve vector
#define Tp template
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define pb emplace_back
#define fir first
#define sec second
// the cmin && cmax
Tp<class T> void cmax(T &x, const T &y)
{
    if (x < y)
        x = y;
}
Tp<class T> void cmin(T &x, const T &y)
{
    if (x > y)
        x = y;
}
// sort , unique , reverse
Tp<class T> void sort(ve<T> &v)
{
    sort(all(v));
}
Tp<class T> void unique(ve<T> &v)
{
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}
Tp<class T> void reverse(ve<T> &v)
{
    reverse(all(v));
}
const int SZ = 0x191981;
struct FILEIN
{
    ~FILEIN() {}
    char qwq[SZ], *S = qwq, *T = qwq, ch;
    char GETC()
    {
        return (S == T) && (T = (S = qwq) + fread(qwq, 1, SZ, stdin), S == T) ? EOF : *S++;
    }
    FILEIN &operator>>(char &c)
    {
        while (isspace(c = GETC()))
            ;
        return *this;
    }
    FILEIN &operator>>(string &s)
    {
        while (isspace(ch = GETC()))
            ;
        s = "" + ch;
        while (!isspace(ch = GETC()))
            s += ch;
        return *this;
    }
    Tp<class T> void read(T &x)
    {
        bool sign = 1;
        while ((ch = GETC()) < 0x30)
            if (ch == 0x2d)
                sign = 0;
        x = (ch ^ 0x30);
        while ((ch = GETC()) > 0x2f)
            x = x * 0xa + (ch ^ 0x30);
        x = sign ? x : -x;
    }
    FILEIN &operator>>(int &x)
    {
        return read(x), *this;
    }
    FILEIN &operator>>(signed &x)
    {
        return read(x), *this;
    }
    FILEIN &operator>>(unsigned &x)
    {
        return read(x), *this;
    }
} in;
struct FILEOUT
{
    const static int LIMIT = 0x114514;
    char quq[SZ], ST[0x114];
    signed sz, O;
    ~FILEOUT()
    {
        sz = O = 0;
    }
    void flush()
    {
        fwrite(quq, 1, O, stdout);
        fflush(stdout);
        O = 0;
    }
    FILEOUT &operator<<(char c)
    {
        return quq[O++] = c, *this;
    }
    FILEOUT &operator<<(string str)
    {
        if (O > LIMIT)
            flush();
        for (char c : str)
            quq[O++] = c;
        return *this;
    }
    Tp<class T> void write(T x)
    {
        if (O > LIMIT)
            flush();
        if (x < 0)
        {
            quq[O++] = 0x2d;
            x = -x;
        }
        do
        {
            ST[++sz] = x % 0xa ^ 0x30;
            x /= 0xa;
        } while (x);
        while (sz)
            quq[O++] = ST[sz--];
        return;
    }
    FILEOUT &operator<<(int x)
    {
        return write(x), *this;
    }
    FILEOUT &operator<<(signed x)
    {
        return write(x), *this;
    }
    FILEOUT &operator<<(unsigned x)
    {
        return write(x), *this;
    }
} out;
signed main()
{
#ifdef _WIN64
    freopen("testdata.in", "r", stdin);
#else
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    // code begin.
    int t;
    in >> t;
    while (t--)
    {
        int n, m, k;
        in >> n >> m >> k;
        ve<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            in >> a[i];
        int ans = 0, qwq = max(0ll, m - k - 1);
        if (qwq)
        {
            for (int i = 0; i <= min(m - 1, k); i++)
            {
                int le = i + 1;
                int ri = n - k + i;
                int mn = 1e9;
                for (int j = 0; j <= qwq; j++)
                    cmin(mn, max(a[le + j], a[ri - qwq + j]));
                cmax(ans, mn);
            }
            out << ans << '\n';
        }
        else
        {
            for (int i = 1; i <= n; i++)
                if (n < i + m || m >= i)
                    cmax(ans, a[i]);
            out << ans << '\n';
        }
    }
    return out.flush(), 0;
    // code end.
}
