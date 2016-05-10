#include <bits/stdc++.h>

using namespace std;

int n, res;

int main()
{
	cin >> n;
	res = n / 3 * 2 + (n % 3 != 0);
	cout << res;
	return 0;
}