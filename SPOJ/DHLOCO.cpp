#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, modd;

struct Matrix {
	ll a[3][3];

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator*(const Matrix& m) const {
		Matrix res;
		for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		for (int k = 0; k < 3; ++k)
			res.a[i][j] = (res.a[i][j] + this->a[i][k] * m.a[k][j]) % modd;

		return res;
	}
};

Matrix myPow(Matrix x, ll y) {
	if (y == 1)
		return x;

	Matrix res = myPow(x, y>>1);
	res = res * res;
	if (y&1)
		res = res * x;
	return res;
}

int main() {
	scanf("%lld %lld", &n, &modd);

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	Matrix m;
	m.a[0][1] = m.a[1][2] = m.a[2][0] = m.a[2][1] = m.a[2][2] = 1;

	m = myPow(m, n-1);
	ll res = (m.a[0][0]*1 + m.a[0][1]*2 + m.a[0][2]*4) % modd;

	printf("%lld\n", res);
	return 0;
}