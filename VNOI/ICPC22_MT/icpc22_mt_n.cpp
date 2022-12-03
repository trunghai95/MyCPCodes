#include <stdio.h>

using namespace std;

int test, n;

int main() {
    scanf("%d", &test);
    while (test --> 0) {
        scanf("%d", &n);
        printf("%.9lf\n", 1000000000.0/(n+1));
    }
    return 0;
}