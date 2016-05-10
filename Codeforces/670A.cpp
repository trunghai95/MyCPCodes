#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin >> n;
	int w = n / 7;
	int d = n % 7;
	cout << w*2 + (d == 6? 1: 0) << ' ' << w*2 + (d < 3 ? d : 2);
	return 0;
}