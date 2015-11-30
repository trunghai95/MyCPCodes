#include <bits/stdc++.h>

using namespace std;

int test, n, cnt[8];
char s[50];

int Hash(int pos)
{
    return (s[pos] == 'H')*4 + (s[pos+1] == 'H')*2 + (s[pos+2] == 'H');
}

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> test;
	while (test--)
    {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> s;
        for (int i = 0; i <= 37; ++i)
            ++cnt[Hash(i)];

        cout << n;
        for (int i = 0; i < 8; ++i)
            cout << ' ' << cnt[i];

        cout << endl;
    }

    return 0;
}
