#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
bool ck[1111];

int main()
{
    cin >> n;
    memset(ck,0,sizeof(ck));
    for (int i = 2; i <= n; ++i)
    if (!ck[i])
    {
        ck[i] = 1;
        v.push_back(i);
        for (int j = i*i; j <= n; j *= i)
        {
            v.push_back(j);
            ck[j] = 1;
        }
        for (int j = i*i; j <= n; j += i)
            ck[j] = 1;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    return 0;
}
