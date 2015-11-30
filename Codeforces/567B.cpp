#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 7;
int n, a, res=0, cnt=0;
bool ck[MAX];
string s;

int main()
{
    memset(ck,0,sizeof(ck));
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> a;
        if (s == "+")
        {
            ck[a] = 1;
            ++cnt;
            if (cnt > res) res = cnt;
        }
        else
        {
            if (!ck[a])
                ++res;
            else
            {
                ck[a] = 0;
                --cnt;
            }
        }
    }
    cout << res;
    return 0;
}
