#include <bits/stdc++.h>

using namespace std;

int n;

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;

    for (int i = 2; i*i <= n; ++i)
    if (n % i == 0) {
        return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= 1000; ++i)
    if (!isPrime(n*i + 1)) {
        printf("%d\n", i);
        return 0;
    }
    return 0;
}
