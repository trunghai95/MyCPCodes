#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MODD = (1<<20);
const int MAXX = 25;

ll nextRand(ll x) {
	return (487237LL*x + 1011807LL) % MODD;
}

int sumbits(ll n) {
	int res = 0;
	while (n) {
		res += (n&1);
		n >>= 1;
	}
	return (res&1);
}

int n, arr[MAXX + 5];

int play(int x) {
	printf("%d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	if (x == -1) exit(0);
	return x;
}

int main() {
	srand(time(0));
	scanf("%d", &n);
	if (n == -1) return 0;

	for (int i = 0; i < MAXX; ++i) {
		int m = play(1);
		arr[i] = (m > n);
		n = m;
	}

	int tmp;
	for (int i = 0; i < MODD; ++i) {
		tmp = i;
		bool found = true;

		for (int j = 0; found && j < MAXX; ++j) {
			if (sumbits(tmp) != arr[j]) {
				found = false;
			} else {
				tmp = nextRand(tmp);
			}
		}
		if (found) break;
	}

	while (true) {
		if (sumbits(tmp)) {
			n = play(min(n, 200));
		} else {
			n = play(1);
		}
		tmp = nextRand(tmp);
	}
	return 0;
}