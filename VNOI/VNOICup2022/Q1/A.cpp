#include <stdio.h>

const int MAXN = 100005;
int n, a[MAXN], b[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", b+i);
    }

    int i = 0, j = 0;
    int last = -1;
    while (i < n || j < n) {
        if (i >= n) {
            last = b[j];
            j++;
            printf("b");
        } else if (j >= n) {
            last = a[i];
            i++;
            printf("a");
        } else {
            if (a[i] == last) {
                last = b[j];
                j++;
                printf("b");
            } else if (b[j] == last) {
                last = a[i];
                i++;
                printf("a");
            } else if (i < n-1 && b[j] == a[i+1]) {
                last = b[j];
                j++;
                printf("b");
            } else if (j < n-1 && a[i] == b[j+1]) {
                last = a[i];
                i++;
                printf("a");
            } else {
                last = a[i];
                i++;
                printf("a");
            }
        }
    }
    printf("\n");
    return 0;
}