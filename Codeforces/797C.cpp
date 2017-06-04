#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
char s[MAXN+5], mn[MAXN+5];
stack<char> st;

int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);

    mn[n] = s[n];
    for (int i = n - 1; i > 0; --i) {
        mn[i] = min(s[i], mn[i+1]);
    }

    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && st.top() <= mn[i]) {
            printf("%c", st.top());
            st.pop();
        }
        st.push(s[i]);
    }

    while (!st.empty()) {
        printf("%c", st.top());
        st.pop();
    }
    printf("\n");
    return 0;
}
