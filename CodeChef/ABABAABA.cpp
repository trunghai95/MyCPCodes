#include <bits/stdc++.h>

using namespace std;

string s;
int test, n;

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> s;

		int cntA = 0, cntB = 0;
		n = s.length();
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'A')
				++cntA;
			else
				++cntB;
		}

		if (cntA == 2)
			cout << "A\n";
		else if (cntB == 2)
			cout << "B\n";
		else if (n <= 2)
			cout << "-1\n";
		else
		{
			if (s[0] == s[1] && s[2] != s[1])
			{
				cout << s[0] << string(s.begin() + 2, s.end()) << '\n';
				continue;
			}
			else if (s[n-1] == s[n-2] && s[n-3] != s[n-2])
			{
				cout << string(s.begin(), s.begin() + n - 2) << s[n-1] << '\n';
				continue;
			}
			else
			{
				int i;
				for (i = 1; i < n - 2; ++i)
				if (s[i] == s[i+1] && s[i-1] != s[i] && s[i+2] != s[i])
				{
					cout << string(s.begin(), s.begin() + i)
						<< s[i] << string(s.begin() + i + 2, s.end()) << '\n';
					break;
				}

				if (i >= n - 2)
					cout << "-1\n";
			}
		}
	}
	return 0;
}