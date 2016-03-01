#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	b = (c - a) / b;

	cout << ((b&1)? "Unlucky Chef" : "Lucky Chef");
	return 0;
}