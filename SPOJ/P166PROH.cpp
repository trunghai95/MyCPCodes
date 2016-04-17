#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void init()
{
	for (int i = 2; i <= 3000; ++i)
	{
		bool f = true;
		for (int j = 2; j*j <= i && f; ++j)
		if (i % j == 0)
			f = false;

		if (f)
		{
			int tmp = i;
			while (tmp <= 3000)
				v.push_back(tmp), tmp *= i;
		}
	}
}

int n, res;

int main()
{
	init();
	cin >> n;

	for (int i = 0; i < v.size(); ++i)
	for (int j = i+1; j < v.size(); ++j)
		res += (v[i]*v[j] <= n && v[i] % v[j] != 0 && v[j] % v[i] != 0);

	cout << res;
	return 0;
}