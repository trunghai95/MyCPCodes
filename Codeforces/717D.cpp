#include <bits/stdc++.h>

using namespace std;

struct Matrix {
	double a[128][128];

	Matrix(double a[][128]) {
		for (int i = 0; i < 128; ++i)
		for (int j = 0; j < 128; ++j)
			this->a[i][j] = a[i][j];
	}

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator*(Matrix m) {
		Matrix res;
		for (int i = 0; i < 128; ++i)
		for (int j = 0; j < 128; ++j)
		for (int k = 0; k < 128; ++k)
			res.a[i][j] += this->a[i][k] * m.a[k][j];

		return res;
	}
};

int n, x;
double a[128][128], p[128];

Matrix myPow(Matrix m, int n) {
	Matrix res;
	for (int i = 0; i < 128; ++i)
		res.a[i][i] = 1;

	while (n) {
		if (n&1)
			res = res * m;
		m = m*m;
		n /= 2;
	}

	return res;
}

int main() {
	scanf("%d %d", &n, &x);

	for (int i = 0; i <= x; ++i)
		scanf("%lf", p+i);

	if (n == 1) {
		printf("%.8lf\n", 1.0 - p[0]);
		return 0;
	}

	for (int i = 0; i < 128; ++i)
	for (int j = 0; j < 128; ++j)
		a[i][j] = p[i^j];

	Matrix m(a);
	m = myPow(m, n - 1);
	double res = 0;

	for (int i = 0; i <= x; ++i)
		res += p[i] * m.a[i][0];

	printf("%.8lf\n", 1.0 - res);
	return 0;
}