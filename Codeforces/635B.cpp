#include <bits/stdc++.h>

using namespace std;

int n, a[200010], b[200010], sa, sb;
vector<int> va, vb;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b+i);

	for (int i = 0; i < n; ++i)
	if (a[i] == 1)
	{
		sa = i;
		break;
	}

	for (int i = 0; i < n; ++i)
	if (a[(sa + i) % n])
		va.push_back(a[(sa + i) % n]);

	for (int i = 0; i < n; ++i)
	if (b[i] == 1)
	{
		sb = i;
		break;
	}

	for (int i = 0; i < n; ++i)
	if (b[(sb + i) % n])
		vb.push_back(b[(sb + i) % n]);

	for (int i = 0; i < va.size(); ++i)
	{
		if (va[i] != vb[i])
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}