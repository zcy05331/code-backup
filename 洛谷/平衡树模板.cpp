#include <bits/stdc++.h>
#define update(x) tree[x].size = tree[tree[x].left].size + tree[tree[x].right].size + 1;
const int MaxN = 100010;
const int inf = 0x3f3f3f3f;

struct node
{
	int val;
	int left;
	int right;
	int size;
} tree[MaxN];

int root, size;

void lturn(int &x)
{
	int y = tree[x].right;
	tree[x].right = tree[y].left;
	tree[y].left = x;
	tree[y].size = tree[x].size;
	update(x);
	x = y;
}

void rturn(int &x)
{
	int y = tree[x].left;
	tree[x].left = tree[y].right;
	tree[y].right = x;
	tree[y].size = tree[x].size;
	update(x);
	x = y;
}

void maintain(int &x, int flag)
{
	if (flag == false)
	{
		if (tree[tree[tree[x].left].left].size > tree[tree[x].right].size)
			rturn(x);
		else if (tree[tree[tree[x].left].right].size > tree[tree[x].right].size)
		{
			lturn(tree[x].left);
			rturn(x);
		}
		else
			return;
	}
	else
	{
		if (tree[tree[tree[x].right].right].size > tree[tree[x].left].size)
			lturn(x);
		else if (tree[tree[tree[x].right].left].size > tree[tree[x].left].size)
		{
			rturn(tree[x].right);
			lturn(x);
		}
		else
			return;
	}
	maintain(tree[x].left, false);
	maintain(tree[x].right, true);
	maintain(x, true);
	maintain(x, false);
}

void insert(int &x, int val)
{
	if (x == 0)
	{
		x = ++size;
		tree[x].left = tree[x].right = 0;
		tree[x].size = 1;
		tree[x].val = val;
	}
	else
	{
		tree[x].size++;
		if (val < tree[x].val)
			insert(tree[x].left, val);
		else
			insert(tree[x].right, val);
		maintain(x, val >= tree[x].val);
	}
}

int remove(int &x, int val)
{
	int d_val = 0;
	tree[x].size--;
	if ((val == tree[x].val) || (val < tree[x].val && tree[x].left == 0) ||
		(val > tree[x].val && tree[x].right == 0))
	{
		d_val = tree[x].val;
		if (tree[x].left && tree[x].right)
		{
			tree[x].val = remove(tree[x].left, tree[x].val + 1);
		}
		else
		{
			x = tree[x].left + tree[x].right;
		}
	}
	else if (val > tree[x].val)
		d_val = remove(tree[x].right, val);
	else if (val < tree[x].val)
		d_val = remove(tree[x].left, val);
	return d_val;
}

int query_min()
{
	int x;
	for (x = root; tree[x].left; x = tree[x].left)
		;
	return tree[x].val;
}

int query_max()
{
	int x;
	for (x = root; tree[x].right; x = tree[x].right)
		;
	return tree[x].val;
}

int query_num(int x, int k)
{
	int r = tree[tree[x].left].size + 1;
	if (r == k)
		return tree[x].val;
	else if (r < k)
		return query_num(tree[x].right, k - r);
	else
		return query_num(tree[x].left, k);
}

int query_rank(int k, int x)
{
	if (k == 0)
		return 0;
	if (tree[k].val == x)
		return tree[tree[k].left].size + 1;
	else if (x > tree[k].val)
		return tree[tree[k].left].size + 1 + query_rank(tree[k].right, x);
	else
		return query_rank(tree[k].left, x);
}

int query_pro(int x, int y, int val)
{
	if (x == 0)
		return y;
	if (tree[x].val < val)
		return query_pro(tree[x].right, x, val);
	else
		return query_pro(tree[x].left, y, val);
}

int query_sub(int x, int y, int val)
{
	if (x == 0)
		return y;
	if (tree[x].val > val)
		return query_sub(tree[x].left, x, val);
	else
		return query_sub(tree[x].right, y, val);
}

int main()
{
	freopen("SBT.out", "w", stdout);
	int n;
	int ans;
	scanf("%d", &n);
	int opt, x;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &opt, &x);
		if (opt == 1)
			insert(root, x);
		if (opt == 2)
			remove(root, x);
		if (opt == 3)
			printf("%d\n", i, query_rank(root, x));
		if (opt == 4)
			printf("%d\n", i, query_num(root, x));
		if (opt == 5)
		{
			ans = query_pro(root, 0, x), printf("%d\n", i, tree[ans].val);
		}
		if (opt == 6)
		{
			ans = query_sub(root, 0, x), printf("%d\n", i, tree[ans].val);
		}
	}
	return 0;
}