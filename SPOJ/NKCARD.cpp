#include <bits/stdc++.h>

using namespace std;

int k, m;
char s[100010];
deque<int> q;

int main() {
	scanf("%d %d %s", &m, &k, s);

	for (int i = 0; i < m; ++i)
		q.push_back(i);

	for (int i = 0; s[i] != '.'; ++i) {
		if (s[i] == 'A') {
			q.push_back(q.front());
			q.pop_front();
		} else if (s[i] == 'B') {
			int tmp = q.front();
			q.pop_front();
			q.push_back(q.front());
			q.pop_front();
			q.push_front(tmp);
		} else break;
	}

	for (int i = 0; i < k-1; ++i)
		q.pop_front();
	for (int i = 0; i < 3; ++i)
		printf("%d ", q.front()), q.pop_front();
	printf("\n");
	return 0;
}