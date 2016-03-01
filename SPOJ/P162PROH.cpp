#include <bits/stdc++.h>

using namespace std;

int x, i, sum;

int main()
{
	cin >> x;
	i = 0;

	while (x >= 0)
		++i, sum += i, x -= sum;

	cout << i-1;
	return 0;
}