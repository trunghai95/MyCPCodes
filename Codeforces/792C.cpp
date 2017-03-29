#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int len, sum;
deque<int> pos[3];
char s[MAXN+2];

void print(int l, int r) {
    for (int i = l; i <= r; ++i)
        printf("%c", s[i]);
}

int main() {
    scanf("%s", s);
    len = strlen(s);

    for (int i = 0; i < len; ++i) {
        int d = (s[i] - '0') % 3;
        if (pos[d].size() == 2) {
            pos[d].pop_front();
        }
        pos[d].push_back(i);
        sum += d;
    }

    sum %= 3;

    if (sum == 0) {
        printf("%s\n", s);
        return 0;
    }

    if (sum == 1) {
        int c1 = -1, c2 = -1;
        if (pos[1].size() > 0) {
            if (pos[1].back() > 0) {
                print(0, pos[1].back() - 1);
                print(pos[1].back() + 1, len - 1);
                printf("\n");
                return 0;
            }

            c1 = 1;
            while (c1 < len && s[c1] == '0') {
                ++c1;
            }

            if (c1 == len) {
                if (pos[0].size() > 0) {
                    printf("0\n");
                    return 0;
                } else {
                    c1 = -1;
                }
            }

            if (c1 == 1) {
                printf("%s\n", s+1);
                return 0;
            }
        }

        if (pos[2].size() > 1) {
            if (pos[2].front() > 0) {
                print(0, pos[2].front() - 1);
                print(pos[2].front() + 1, pos[2].back() - 1);
                print(pos[2].back() + 1, len - 1);
                printf("\n");
                return 0;
            }

            c2 = 1;
            while (c2 < len && s[c2] == '0') {
                ++c2;
            }

            if (c2 == pos[2].back()) {
                ++c2;
                while (c2 < len && s[c2] == '0') {
                    ++c2;
                }
                if (c1 == -1) {
                    c1 = c2;
                } else {
                    c1 = min(c1, c2);
                }
                c2 = -1;
            }

            if (c1 == len) {
                if (pos[0].size() > 0) {
                    printf("0\n");
                    return 0;
                } else {
                    c1 = -1;
                }
            }
        }

        if (c1 == -1 && c2 == -1) {
            printf("-1\n");
        } else if (c1 == -1 || (c2 != -1 && c2 + 1 < c1)) {
            print(c2, pos[2].back() - 1);
            print(pos[2].back() + 1, len - 1);
            printf("\n");
        } else {
            print(c1, len - 1);
            printf("\n");
        }
        return 0;
    }

    if (sum == 2) {
        int c1 = -1, c2 = -1;
        if (pos[2].size() > 0) {
            if (pos[2].back() > 0) {
                print(0, pos[2].back() - 1);
                print(pos[2].back() + 1, len - 1);
                printf("\n");
                return 0;
            }

            c1 = 1;
            while (c1 < len && s[c1] == '0') {
                ++c1;
            }

            if (c1 == len) {
                if (pos[0].size() > 0) {
                    printf("0\n");
                    return 0;
                } else {
                    c1 = -1;
                }
            }

            if (c1 == 1) {
                printf("%s\n", s+1);
                return 0;
            }
        }

        if (pos[1].size() > 1) {
            if (pos[1].front() > 0) {
                print(0, pos[1].front() - 1);
                print(pos[1].front() + 1, pos[1].back() - 1);
                print(pos[1].back() + 1, len - 1);
                printf("\n");
                return 0;
            }

            c2 = 1;
            while (c2 < len && s[c2] == '0') {
                ++c2;
            }

            if (c2 == pos[1].back()) {
                ++c2;
                while (c2 < len && s[c2] == '0') {
                    ++c2;
                }
                if (c1 == -1) {
                    c1 = c2;
                } else {
                    c1 = min(c1, c2);
                }
                c2 = -1;
            }

            if (c1 == len) {
                if (pos[0].size() > 0) {
                    printf("0\n");
                    return 0;
                } else {
                    c1 = -1;
                }
            }
        }

        if (c1 == -1 && c2 == -1) {
            printf("-1\n");
        } else if (c1 == -1 || (c2 != -1 && c2 + 1 < c1)) {
            print(c2, pos[1].back() - 1);
            print(pos[1].back() + 1, len - 1);
            printf("\n");
        } else {
            print(c1, len - 1);
            printf("\n");
        }
    }
    return 0;
}
