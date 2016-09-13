#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int test, a, b;
bool notPrime[MAX + 10];
vector<int> primes;

void init() {
	for (int i = 2; i <= MAX; ++i)
	if (!notPrime[i]) {
		primes.push_back(i);
		for (int j = i*i; j <= MAX; j += i)
			notPrime[j] = true;
	}
}

int cntPrimeDiv(int x) {
	if (x == 1)
		return 1;

	int res = 1;

	for (int i = 0; i < (int)primes.size(); ++i) {
		int p = primes[i];
		if (p*p > x)
			break;
		int tmp = 0;
		while (x % p == 0)
			++tmp, x /= p;

		res *= tmp+1;
	}

	if (x > 1)
		res *= 2;

	return res;
}

int main() {
	init();
	
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %d", &a, &b);
		int res = 0, mx = 0;

		for (int i = a; i <= b; ++i) {
			int tmp = cntPrimeDiv(i);
			if (tmp > mx) {
				res = 1;
				mx = tmp;
			} else if (tmp == mx) {
				++res;
			}
		}

		printf("%d\n", res+1);
	}
	return 0;
}