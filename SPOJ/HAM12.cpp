#include <bits/stdc++.h>

using namespace std;

int n, m, k, res = 2e9, cnt;
char s[2010], t[1010];

int main() {

	scanf("%d %d %d %s", &n, &m, &k, s);

	memcpy(s+n, s, (m-1)*sizeof(char));
	n += m-1;

	while (k --> 0) {
		scanf("%s", t);

		for (int i = 0; i < n - m + 1; ++i) {
			cnt = 0;
			for (int j = 0; j < m; ++j) {
				// cout << t[j] << ' ' << s[i+j] << '\n';
				if (t[j] != s[i + j] && ++cnt >= res) {
					break;
				}
			}
			res = min(res, cnt);
		}
	}

	printf("%d\n", res);
	return 0;
}