#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4 + 1;
const int MOD = 1e4 + 7;
int test, n, a[MAX];

struct base {
    double a, b;
    base(): a(0), b(0) {}
    base(double a, double b): a(a), b(b) {}
    base(double a): a(a), b(0) {}

    double real() { return a; }
    base operator*(const base& other) const {
        return base(this->a*other.a - this->b*other.b, this->a*other.b + this->b*other.a);
    }
    base operator+(const base& other) const {
        return base(this->a + other.a, this->b + other.b);
    }
    base operator-(const base& other) const {
        return base(this->a - other.a, this->b - other.b);
    }
    void operator/=(const double& x) {
        a /= x;
        b /= x;
    }
};

const double PI = acos(-1);

void fft(base *&a, const int& szA, bool invert){
    int n = szA;
    if (n == 1)
        return;
    base *a0 = new base[n / 2];
    base *a1 = new base[n / 2];
    //vector <base> a0(n / 2), a1(n / 2);
    for (int i = 0, j = 0; i < n; i += 2, ++j){
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }
    fft(a0, n/2, invert);
    fft(a1, n/2, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    base w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < n / 2; ++i){
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2, a[i + n / 2] /= 2;
        w = w*wn;
    }
}

void multiply(int *const& a, const int& szA, int *const& b, const int& szB, int *& res){
    size_t n = 1;
    while (n < max(szA, szB)) n <<= 1;
    n <<= 1;
    base *fa = new base[n];
    base *fb = new base[n];
    for (int i = 0; i < n; ++i) {
        if (i < szA) {
            fa[i] = base(a[i]);
        } else {
            fa[i] = base();
        }

        if (i < szB) {
            fb[i] = base(b[i]);
        } else {
            fb[i] = base();
        }
    }

    fft(fa, n, false), fft(fb, n, false);
    for (size_t i = 0; i < n; ++i)
        fa[i] = fa[i] * fb[i];
    fft(fa, n, true);

    res = new int[n];
    for (size_t i = 0; i < n; ++i)
        res[i] = int(fa[i].real() + 0.5) % MOD;
}

int* cal(const int& lef, const int& rig){
    if (lef == rig){
        int* res = new int[2];
        res[0] = 1;
        res[1] = a[lef];
        return res;
    }
    int mid = (lef + rig) >> 1;
    int* lef_res = cal(lef, mid);
    int* rig_res = cal(mid + 1, rig);
    int* res;
    multiply(lef_res, mid - lef + 2, rig_res, rig - mid + 1, res);
    return res;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);
    while (test--){
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i){
            scanf("%d", a + i);
            //a[i] = i;
            a[i] %= MOD;
        }
        int* res = cal(1, n);
        for (int i = 1; i <= n; ++i)
            printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}
