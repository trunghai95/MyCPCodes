#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll a, b, res;

int popcount(ll x) {
	int res = 0;
	while (x) {
		if (x&1)
			++res;
		x >>= 1;
	}
	return res;
}

bool getbit(ll x, int pos) {
	return ((x >> pos) & 1) != 0;
}

int main() {

	scanf("%d", &test);

	while (test--) {
		scanf("%lld %lld", &a, &b);
		if (a == b)
		{
			printf("%lld\n", a);
			continue;
		}

		res = 0;

		int pos = 62;

		while (pos >= 0) {
			bool bit = getbit(a, pos);
			if (bit == getbit(b, pos)) {
				if (bit)
					res |= (1LL << pos);
			} else {
				res |= ((1LL << pos) - 1);
				break;
			}
			--pos;
		}

		if (popcount(res) < popcount(b))
			res = b;
		printf("%lld\n", res);
	}
	return 0;
}