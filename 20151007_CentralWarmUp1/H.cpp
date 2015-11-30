#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y;

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int test;
	cin >> test;

	while (test--)
    {
        cin >> x >> y;
        if (x < y) cout << "NO BRAINS\n";
        else cout << "MMM BRAINS\n";
    }

    return 0;
}
