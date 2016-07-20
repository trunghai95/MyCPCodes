#include <bits/stdc++.h>

using namespace std;

int n, p[200010], root, pp[200010];
bool ck[200010], ck2[200010];

void dfs(int u)
{
	ck2[u] = true;
	if (ck2[p[u]])
	{
		// cout << u << ' ' << p[u] << '\n';
		if (root == 0)
			root = p[u], p[p[u]] = p[u];
		else
			p[p[u]] = root;
		ck[p[u]] = true;
	}
	else if (!ck[p[u]])
		dfs(p[u]);
	ck[u] = true;
	ck2[u] = false;
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", p+i);

	memcpy(pp+1, p+1, n*sizeof(int));

	for (int i = 1; i <= n; ++i)
	if (p[i] == i)
	{
		if (root == 0)
			root = i;
		else
			p[i] = root;
		ck[i] = true;
	}

	for (int i = 1; i <= n; ++i)
	if (!ck[i])
		dfs(i);

	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += (p[i] != pp[i]);
	printf("%d\n", res);

	for (int i = 1; i <= n; ++i)
		printf("%d ", p[i]);
	return 0;
}