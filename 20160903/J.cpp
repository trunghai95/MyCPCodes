#include <bits/stdc++.h>

using namespace std;

int test, n;
char s[50];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);
		set<string> st;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			st.insert(string(s));
		}

		printf("%d\n", st.size());
	}
	return 0;
}