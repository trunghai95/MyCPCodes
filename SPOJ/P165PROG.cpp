#include <bits/stdc++.h>

using namespace std;

char s1[111], s2[111];
char b;
short s;
int i;
long long l;

int main()
{
	cin >> s1;
	sscanf(s1, "%lld", &l);
	sscanf(s1, "%d", &i);
	s = i;
	b = i;

	sprintf(s2, "%lld", l);
	if (strcmp(s1, s2))
	{
		cout << "BigInteger";
		return 0;
	}

	sprintf(s2, "%d", i);
	if (strcmp(s1, s2))
	{
		cout << "long";
		return 0;
	}

	sprintf(s2, "%d", (int)s);
	if (strcmp(s1, s2))
	{
		cout << "int";
		return 0;
	}

	sprintf(s2, "%d", (int)b);
	if (strcmp(s1, s2))
	{
		cout << "short";
		return 0;
	}

	cout << "byte";
	return 0;
}