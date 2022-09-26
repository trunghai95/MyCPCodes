#include <stdio.h>
#include <stack>

#define ll long long

using namespace std;

const int MAXN = 1000006;
int n;
ll k;
char res[MAXN], valid[MAXN];

void solveOdd() {
    k--;
    for (int i = n-1; i >= 0; i--) {
        if (k&1) {
            res[i] = ')';
        } else {
            res[i] = '(';
        }
        k >>= 1;
    }

    printf("%s\n", res);
}

void incrementRes() {
    bool canIncr = false;
    for (int i = 0; i < n; i++) {
        if (res[i] == '(') {
            canIncr = true;
            break;
        }
    }
    if (!canIncr) {
        return;
    }
    for (int i = n-1; i >= 0; i--) {
        if (res[i] == '(') {
            res[i] = ')';
            return;
        }
        res[i] = '(';
    }
}

bool incrementValid() {
    // TODO
    int cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        if (valid[i] == ')') {
            cnt++;
        } else {
            cnt--;
        }
        if (valid[i] == '(' && cnt > 0) {
            valid[i] = ')';
            for (int j = i+1; j < n; j++) {
                if (valid[j] == ')') {
                    valid[j] = '(';
                    break;
                }
            }
            return true;
        }
    }
    return false;
}

bool isValid() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (res[i] == '(') {
            ++cnt;
        } else {
            if (cnt <= 0) {
                return false;
            }
            --cnt;
        }
    }
    return cnt == 0;
}

// void solveEven() {
//     for (int i = 0; i < n; i++) {
//         res[i] = '(';
//     }
//     k--;
//     while (k) {
//         incrementRes();
//         while (isValid()) {
//             incrementRes();
//         }
//         --k;
//     }
//     printf("%s\n", res);
// }

bool validLessThanRes() {
    for (int i = 0; i < n; i++) {
        if (valid[i] < res[i]) {
            return true;
        }
        if (valid[i] > res[i]) {
            return false;
        }
    }
    return true;
}

void solveEven() {
    for (int i = 0; i < n/2; i++) {
        valid[i] = '(';
    }
    for (int i = n/2; i < n; i++) {
        valid[i] = ')';
    }

    // for (int i = 0; i < 10; i++) {
    //     incrementValid();
    //     printf("%s\n", valid);
    // }

    k--;
    for (int i = n-1; i >= 0; i--) {
        if (k&1) {
            res[i] = ')';
        } else {
            res[i] = '(';
        }
        k >>= 1;
    }

    while (validLessThanRes()) {
        // printf("valid:%s res:%s\n", valid, res);
        incrementRes();
        if (!incrementValid()) {
            break;
        }
    }

    printf("%s\n", res);
}

int main() {
    scanf("%d %lld", &n, &k);
    if (n % 2 != 0 || n >= 120) {
        solveOdd();
    } else {
        solveEven();
    }
    return 0;
}