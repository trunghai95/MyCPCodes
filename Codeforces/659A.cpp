#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main()
{
	cin >> n >> a >> b;

	a = (a - 1 + (b%n) + n*n) % n + 1;
	cout << a;
	return 0;
}