#include <bits/stdc++.h>

using namespace std;

struct Person {
	string name;
	string level;
};

bool operator<(const Person& x, const Person& y) {
	if (x.level == y.level)
		return x.name < y.name;

	return x.level < y.level;
}

int n, mx;
char s[300];
Person p[1010];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		s[strlen(s) - 1] = 0;
		p[i].name = string(s);

		while (1) {
			scanf("%s", s);
			if (!strcmp(s, "class"))
				break;
			if (!strcmp(s, "upper"))
				p[i].level.push_back('0');
			else if (!strcmp(s, "middle"))
				p[i].level.push_back('1');
			else if (!strcmp(s, "lower"))
				p[i].level.push_back('2');
		}

		reverse(p[i].level.begin(), p[i].level.end());
		mx = max(mx, (int)p[i].level.length());
	}

	for (int i = 0; i < n; ++i)
	while ((int)p[i].level.length() < mx)
		p[i].level.push_back('1');

	sort(p, p+n);

	for (int i = 0; i < n; ++i)
		printf("%s\n", p[i].name.c_str());
	return 0;
}