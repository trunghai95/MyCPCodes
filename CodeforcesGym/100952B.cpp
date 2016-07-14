#include <bits/stdc++.h>

using namespace std;

int n, m, test;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> test;

	while (test--)
	{
		cin >> n >> m;
		++n;
		int t = 0, done = 1;

		while (done < n)
		{
			if (done < m)
				done *= 2, ++t;
			else
			{
				int tmp = n - done;
				t += tmp / m + (tmp % m != 0);
				break;
			}

			// cout << done << ' ' << t << '\n';
		}

		cout << t << '\n';
	}
	return 0;
}