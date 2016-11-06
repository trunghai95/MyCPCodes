#include <bits/stdc++.h>

using namespace std;

int test, n;

int cmp(int i, int j) {
	char s[5];
	printf("? %d %d\n", i, j);
	fflush(stdout);
	scanf("%s", s);
	if (s[0] == '<') return -1;
	if (s[0] == '=') return 0;
	return 1;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);
		vector<int> v1, v2;

		for (int i = 1; i < n; i += 2) {
			int tmp = cmp(i, i+1);
			if (tmp < 0) {
				v1.push_back(i);
				v2.push_back(i+1);
			} else {
				v2.push_back(i);
				v1.push_back(i+1);
			}
		}
		if (n&1) v1.push_back(n), v2.push_back(n);

		for (int i = 0; i < (int)v1.size() - 1; i += 2) {
			int tmp = cmp(v1[i], v1[i + 1]);
			if (tmp < 0) v1.push_back(v1[i]);
			else v1.push_back(v1[i+1]);
		}
		for (int i = 0; i < (int)v2.size() - 1; i += 2) {
			int tmp = cmp(v2[i], v2[i + 1]);
			if (tmp > 0) v2.push_back(v2[i]);
			else v2.push_back(v2[i+1]);
		}
		printf("! %d %d\n", v1.back(), v2.back());
		fflush(stdout);
	}
	return 0;
}