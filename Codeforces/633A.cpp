#include <bits/stdc++.h>

using namespace std;

bool visited[10009];

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (c % __gcd(a, b) != 0)
	{
		cout << "No";
		return 0;
	}

	visited[0] = true;
	queue<int> q;
	q.push(0);

	while (!q.empty())
	{
		int u = q.front(); q.pop();

		if (u+a <= c && !visited[u+a])
			visited[u+a] = true, q.push(u+a);
		if (u+b <= c && !visited[u+b])
			visited[u+b] = true, q.push(u+b);
	}

	if (visited[c])
		cout << "Yes";
	else
		cout << "No";
	
	return 0;
}