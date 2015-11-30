#include <bits/stdc++.h>

using namespace std;

int n, m;
string name[2] = {"Wilshere","Xavi"};

int main()
{
    cin >> n >> m;
    cout << name[min(n,m)%2];
    return 0;
}
