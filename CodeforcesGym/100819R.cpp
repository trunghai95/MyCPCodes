#include <bits/stdc++.h>

using namespace std;

typedef pair<string,string> pss;

char s[20];
pss v[200];
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		v[i].second = string(s);
		scanf("%s", s);
		v[i].first = string(s);
	}

	sort(v, v+n);

	for (int i = 0; i < n; ++i)
		printf("%s %s\n", v[i].second.c_str(), v[i].first.c_str());
	return 0;
}