#include <bits/stdc++.h>

using namespace std;

int test, n, m, a, b, it[400010], type;
queue<int> divisors[100010];
vector<int> primes;
bool notPrime[1010], one[400010];

void init() {
	for (int i = 2; i <= 1000; ++i)
	if (!notPrime[i]) {
		primes.push_back(i);
		for (int j = i*i; j <= 1000; j += i)
			notPrime[j] = true;
	}
}

void initIT(const int& node, const int& lef, const int& rig) {
	if (lef == rig) {
		if (divisors[lef].empty())
			one[node] = true, it[node] = 1;
		else
			it[node] = divisors[lef].front();
		return;
	}

	int mid = ((lef + rig) >> 1);
	initIT(node << 1, lef, mid);
	initIT((node << 1) + 1, mid + 1, rig);

	one[node] = (one[node<<1] & one[(node<<1)+1]);
	it[node] = max(it[node<<1], it[(node<<1)+1]);
}

void update(const int& node, const int& lef, const int& rig,
	const int& i, const int& j) {
	if (lef > j || rig < i || one[node])
		return;

	if (lef == rig) {
		divisors[lef].pop();
		if (divisors[lef].empty())
			one[node] = true, it[node] = 1;
		else
			it[node] = divisors[lef].front();
		return;
	}

	int mid = ((lef + rig) >> 1);
	update(node << 1, lef, mid, i, j);
	update((node << 1) + 1, mid + 1, rig, i, j);

	one[node] = (one[node<<1] & one[(node<<1)+1]);
	it[node] = max(it[node<<1], it[(node<<1)+1]);
}

int get(const int& node, const int& lef, const int& rig,
	const int& i, const int& j) {
	if (lef > j || rig < i) {
		return 0;
	}

	if (lef >= i && rig <= j) {
		return it[node];
	}

	if (one[node]) {
		return 1;
	}

	int mid = ((lef + rig) >> 1);
	int res = max(get(node << 1, lef, mid, i, j), 
		get((node << 1) + 1, mid + 1, rig, i, j));
	return res;
}

int main() {
	init();

	scanf("%d", &test);

	while (test --> 0) {
		memset(it, 0, sizeof(it));
		memset(one, 0, sizeof(one));

		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			while (!divisors[i].empty()) {
				divisors[i].pop();
			}
			scanf("%d", &a);

			for (int j = 0; j < (int)primes.size(); ++j) {
				int p = primes[j];
				while (a % p == 0) {
					divisors[i].push(p);
					a /= p;
				}
			}

			if (a > 1000)
				divisors[i].push(a);
		}

		initIT(1, 1, n);

		while (m --> 0) {
			scanf("%d %d %d", &type, &a, &b);

			if (type) {
				printf("%d ", get(1, 1, n, a, b));
			} else {
				update(1, 1, n, a, b);
			}
		}

		printf("\n");
	}
	return 0;
}