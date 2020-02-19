#include <bits/stdc++.h>
using namespace std;
int a[100000] = {};
int main()
{
	int n, i;
	while (scanf("%d", &n) && n != 0)
		a[i++] = n;
	for (int j = i - 1; j >= 0; j--)
	{
		if (a[j])
			cout << a[j] << " ";
	}
	return 0;
}
