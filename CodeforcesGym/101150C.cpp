#include <bits/stdc++.h>

using namespace std;

int opp[7] = {0,6,5,4,3,2,1};
int top[7][7];

struct Cube {
    int color[7], tmpcol[7];

    void rotate(int i1, int i2) {
        tmpcol[1] = color[i1];
        tmpcol[2] = color[i2];
        tmpcol[3] = color[top[i1][i2]];
        tmpcol[4] = color[opp[top[i1][i2]]];
        tmpcol[5] = color[opp[i2]];
        tmpcol[6] = color[opp[i1]];
    }
};

int n, res;
Cube cube[10];
string s;
map<string, int> id;

int getId(string& s) {
    int &d = id[s];
    if (d == 0) {
        return (d = id.size());
    }
    return d;
}

void init() {
    top[4][2] = top[5][4] = top[3][5] = top[2][3] = 1;
    top[1][4] = top[3][1] = top[6][3] = top[4][6] = 2;
    top[1][2] = top[5][1] = top[6][5] = top[2][6] = 3;
    top[2][1] = top[1][5] = top[5][6] = top[6][2] = 4;
    top[4][1] = top[1][3] = top[3][6] = top[6][4] = 5;
    top[2][4] = top[4][5] = top[5][3] = top[3][2] = 6;
}

void Try(int p) {
    if (p > n) {
        int cnt = 0;
        for (int i = 1; i <= 6; ++i) {
            int col = cube[1].tmpcol[i];
            for (int j = 1; j <= n; ++j)
            for (int k = j+1; k <= n; ++k) {
                if (cube[j].tmpcol[i] == cube[k].tmpcol[i]) {
                    col = cube[j].tmpcol[i];
                    break;
                }
            }

            for (int j = 1; j <= n; ++j)
                cnt += (cube[j].tmpcol[i] != col);
        }
        res = min(res, cnt);
        return;
    }

    for (int i = 1; i <= 6; ++i)
    for (int j = i+1; j <= 6; ++j)
    if (i != opp[j]) {
        cube[p].rotate(i, j);
        Try(p+1);
        cube[p].rotate(j, i);
        Try(p+1);
    }
}

int main() {
    init();
    while (cin >> n) {
        if (n == 0) return 0;

        id.clear();

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                cin >> s;
                cube[i].color[j] = getId(s);
            }
        }

        cube[1].rotate(1, 2);
        res = 1e9;
        Try(2);

        cout << res << '\n';
    }
    return 0;
}