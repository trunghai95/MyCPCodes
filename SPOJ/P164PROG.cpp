#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin >> n;
	int sum = 0, sumtmp = 0;
	int i = 0;

	while (sum <= n)
		sum += (sumtmp += ++i);

	cout << i - 1;
	return 0;
}