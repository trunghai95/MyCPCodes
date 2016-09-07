#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 111539786;
int test;
ll n;

struct Matrix {
	ll a[2][2];

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator*(const Matrix& m) const {
		Matrix res;
		for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		for (int k = 0; k < 2; ++k)
			res.a[i][j] = (res.a[i][j] + this->a[i][k] * m.a[k][j]) % MODD;

		return res;
	}
};

Matrix myPow(const Matrix& x, int y) {
	if (y == 1)
		return x;

	Matrix res = myPow(x, y>>1);
	res = res * res;
	if (y&1)
		res = res * x;

	return res;
}

int main() {

	scanf("%d", &test);

	while (test --> 0) {
		scanf("%lld", &n);

		Matrix m;
		m.a[0][1] = m.a[1][0] = m.a[1][1] = 1;
		m = myPow(m, n);

		ll res = (m.a[0][0] + m.a[0][1]) % MODD;

		printf("%lld\n", res);
	}
	return 0;
}