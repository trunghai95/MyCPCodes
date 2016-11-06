#include <bits/stdc++.h>


using namespace std ;

typedef unsigned long long ll;


bool isPalin(ll x) {
    if (x == 0) return 1 ;
    while (x % 10 == 0) x /= 10;
    int xx = x;
    int y =  0 ;
    while (x) {
        y = y * 10 + x % 10 ;
        x/= 10;
    }

    return xx == y ;
}

void abc() {
    char s[30];
    char t[30];
    for (int i = 1; i <= 1000000000; ++i) {
        ll n;
        sprintf(s, "%d", i);
        strcpy(t, s);
        reverse(t, t+strlen(t));
        if (i == 100){
            int tmp = 1;
            ++tmp;
        }

        if (strlen(t) < 9)
        for (int d = 0; d < 10; ++d) {
            int tmp = strlen(s);
            s[tmp] = d + '0';
            s[tmp+1] = 0;
            strcat(s, t);
            sscanf(s, "%llu", &n);
            while (n < 1e18) {
                if (isPalin(n + 2)) {
                    printf("%llu,\n", n+1);
                }
                n *= 10;
            }
            strcpy(s, t);
        }
        reverse(t, t+strlen(t));
        strcat(s, t);
        sscanf(s, "%llu", &n);
        while (n < 1e18) {
            if (isPalin(n + 2)) {
                printf("%llu\n", n+1);
            }
            n *= 10;
        }
    }
}

int n;

int main() {
    freopen("out.txt", "w", stdout);
    abc();
    return 0 ;
}
