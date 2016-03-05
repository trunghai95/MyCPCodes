#include <bits/stdc++.h>

using namespace std;

char s[200];
char vow[20] = "aeiouy";

int main()
{
	cin >> s;

	for (int i = 0; s[i]; ++i)
	{
		if (s[i] <= 'Z')
			s[i] += 32;
		bool f = true;
		for (int j = 0; j < 6 && f; ++j)
		if (s[i] == vow[j])
			f = false;

		if (f)
			cout << "." << s[i];
	}
	return 0;
}