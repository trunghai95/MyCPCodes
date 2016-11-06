#include <iostream>

using namespace std;

int n, m, tcase ;
bool dd[10000];

int main()
{
    cin >> tcase ;
    while (tcase --) {

        cin >> n >> m ;
        for (int i = 0; i <= n * m; i++) dd[i] = 0;
        for (int i = 1 ; i < n; i++) {

            int x = i * m ;
            int y = ( n- i) * m;
            dd[max(x, y)] = 1;
        }
        for (int i = 1; i < m ; i++) {

            int x = i * n;
            int y = (m - i) * n;
            dd[max(x, y) ] = 1;
        }
        for (int i = 0 ;  i <= n * m ; i++) if ( dd[i])
            cout << i <<' ';
        cout <<endl;
    }
}
