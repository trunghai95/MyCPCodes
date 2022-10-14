#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX = 2e6;
bool notPrime[MAX];
vector<int> primes;
int l, h, res;
char s[20], p[20];

void init() {
    for (int i = 2; i < MAX; i++) {
        if (notPrime[i]) {
            continue;
        }
        primes.push_back(i);
        for (ll j = (ll)i*i; j < (ll)MAX; j += i) {
            notPrime[j] = true;
        }
    }
    // printf("%d\n", primes.size());
}

int main() {
    init();
    scanf("%d %d %s", &l, &h, p);
    l--;
    h--;
    for (int i = l; i <= h; i++) {
        sprintf(s, "%d", primes[i]);
        // printf("%s %s %s\n", s, p, strstr(s, p));
        if (strstr(s, p) != NULL) {
            res++;
        }
    }

    printf("%d\n", res);
    return 0;
}