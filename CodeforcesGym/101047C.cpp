#include <bits/stdc++.h>

using namespace std;

int n, test;
double ang, l, x, y;

struct Matrix {
    double data[3][3];

    Matrix(const bool& isUnit = false) {
        memset(data, 0, sizeof(data));

        if (isUnit)
        for (int i = 0; i < 3; ++i)
            data[i][i] = 1;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix res;
        for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        for (int k = 0; k < 3; ++k) {
            res.data[i][j] += this->data[i][k] * other.data[k][j];
        }
        return res;
    }
};

Matrix myPow(Matrix m, int n) {
    Matrix res(true);

    while (n) {
        if (n&1) {
            res = res * m;
        }
        m = m*m;
        n >>= 1;
    }
    return res;
}

int main() {
    scanf("%d\n", &test);

    while (test --> 0) {
        scanf("%lf %lf %d", &ang, &l, &n);
        ang = ang * M_PI / 180.0;
        Matrix m;
        m.data[0][0] = m.data[1][1] = cos(ang);
        m.data[1][0] = -(m.data[0][1] = sin(ang));
        m.data[0][2] = m.data[1][2] = m.data[2][1] = 0;
        m.data[2][2] = 1;
        m.data[2][0] = l;

        m = myPow(m, n);
        printf("%.12lf %.12lf\n", m.data[2][0], m.data[2][1]);
    }
    return 0;
}
