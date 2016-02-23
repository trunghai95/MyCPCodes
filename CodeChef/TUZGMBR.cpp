#include <bits/stdc++.h>

using namespace std;

int test, n, m;

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> m;

		n = (n-1) % 4;
		m = (m-1) % 3;

		if (n^m)
			cout << "Tuzik\n";
		else
			cout << "Vanya\n";
	}
	return 0;
}