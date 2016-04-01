#include <bits/stdc++.h>

using namespace std;

int n, k, q, t[150010], type, id;
bool ck[150010];
vector<int> v;

bool cmp(int x, int y) { return t[x] > t[y]; }

int main()
{
	scanf("%d %d %d", &n, &k, &q);

	for (int i = 1; i <= n; ++i)
		scanf("%d", t+i);

	for (int i = 0; i < q; ++i)
	{
		scanf("%d %d", &type, &id);

		if (type == 1)
		{
			v.push_back(id);
			ck[id] = true;
			sort(v.begin(), v.end(), cmp);
			if (v.size() > k)
			{
				ck[v.back()] = false;
				v.pop_back();
			}
		}
		else
		{
			if (ck[id])
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}