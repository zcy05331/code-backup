#include <bits/stdc++.h>
#define N 1000020
using namespace std;
typedef double dl;
int n, t = 1;
struct sgt_tag
{
#define ls q << 1
#define rs q << 1 | 1
	int tot, tag[N * 4];
	struct function
	{
		dl k, b;
	} fun[N * 4];
	inline dl val(int x, int id) { return fun[id].k * (x - 1) + fun[id].b; } //因为起始点是1所以x要-1
	inline void ins(dl k, dl b)
	{
		fun[++tot].k = k;
		fun[tot].b = b;
		change(1, 1, N, tot);
	}
	inline void change(int q, int l, int r, int id)
	{
		if (l == r)
		{
			if (val(l, id) > val(l, tag[q]))
				tag[q] = id;
			return;
		}
		int mid = (l + r) >> 1;
		if (fun[id].k > fun[tag[q]].k)
		{
			if (val(mid, id) > val(mid, tag[q]))
				change(ls, l, mid, tag[q]), tag[q] = id;
			else
				change(rs, mid + 1, r, id);
		}
		else
		{
			if (val(mid, id) > val(mid, tag[q]))
				change(rs, mid + 1, r, tag[q]), tag[q] = id;
			else
				change(ls, l, mid, id);
		}
	}
	inline dl query(int q, int l, int r, int x)
	{
		if (l == r)
			return val(l, tag[q]);
		int mid = (l + r) >> 1;
		dl ans = val(x, tag[q]);
		if (x <= mid)
			ans = max(ans, query(ls, l, mid, x));
		else
			ans = max(ans, query(rs, mid + 1, r, x));
		return ans;
	}
} T;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int main()
{
	n = read();
begin:
	if (t > n)
		goto end;
	t++;
	char ch[10];
	scanf("%s", ch);
	if (ch[0] == 'P')
	{
		dl k, b;
		scanf("%lf%lf", &b, &k);
		T.ins(k, b);
	}
	if (ch[0] == 'Q')
	{
		int x = read();
		dl ans = T.query(1, 1, N, x);
		printf("%d\n", (int)ans / 100);
	}
	goto begin;
end:
	return 0;
}