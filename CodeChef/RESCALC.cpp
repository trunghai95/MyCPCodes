#include <bits/stdc++.h>

using namespace std;

struct Player {
	int cnt[7], point, id;
	void read() {
		memset(cnt, 0, sizeof(cnt));

		int n, x;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			++cnt[x];
		}

		point = n;
		sort(cnt+1, cnt+7);
		point += cnt[2] + cnt[3] + cnt[1]*2;
	}

	bool operator<(const Player& p) const {
		return this->point > p.point;
	}
};

int test, n;
Player p[111];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i)
			p[i].id = i, p[i].read();

		sort(p+1, p+n+1);

		if (n == 1 || p[1].point > p[2].point) {
			if (p[1].id == 1)
				printf("chef\n");
			else
				printf("%d\n", p[1].id);
		} else {
			printf("tie\n");
		}
	}
	return 0;
}