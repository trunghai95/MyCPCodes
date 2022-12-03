#include <stdio.h>

using namespace std;

#define ll long long

int n, a;
ll cnt[5], res;

int main () {
    scanf("%d", &n);
    while (n --> 0) {
        scanf("%d", &a);
        cnt[a%5]++;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            int k = (10 - i - j) % 5;
            if (k < j) {
                continue;
            }
            if (i == k) {
                res += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
            } else if (i == j) {
                res += cnt[i]*(cnt[i]-1)/2*cnt[k];
            } else if (j == k) {
                res += cnt[k]*(cnt[k]-1)/2*cnt[i];
            } else {
                res += cnt[i]*cnt[j]*cnt[k];
            }
            // printf("%d %d %d %lld %lld %lld %lld\n", i, j, k, cnt[i], cnt[j], cnt[k], res);
        }
    }
    printf("%lld\n", res);
    return 0;
}