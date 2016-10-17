#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[100010];
vector<int> pos[26];
set<int> st;

int main() {
	scanf("%d %s", &m, s);
	n = strlen(s);

	for (int i = 0; i < n; ++i) {
		pos[s[i] - 'a'].push_back(i);
	}

	for (int c = 0; c < 26; ++c) {
		int cnt = 0;
		bool ok = true;

		for (int i = n-1; ok && i >= m-1; --i) {
			set<int>::iterator it = st.lower_bound(i - m + 1);
			if (it != st.end() && *it <= i) {
				i = *it;
				continue;
			}

			vector<int>::iterator iit = 
				lower_bound(pos[c].begin(), pos[c].end(), i - m + 1);

			if (iit != pos[c].end() && *iit <= i) {
				i = *iit;
				++cnt;
				continue;
			} else {
				ok = false;
			}
		}

		if (ok) {
			for (int i = 0; i < c; ++i) {
				for (int j = 0; j < (int)pos[i].size(); ++j) {
					printf("%c", 'a' + i);
				}
			}
			for (int i = 0; i < cnt; ++i) {
				printf("%c", 'a' + c);
			}
			printf("\n");
			return 0;
		}

		for (int i = 0; i < (int)pos[c].size(); ++i) {
			st.insert(pos[c][i]);
		}
	}
	return 0;
}