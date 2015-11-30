#include <bits/stdc++.h>

using namespace std;

int x[3], y[3];
char c[3] = {'A', 'B', 'C'};

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        cin >> x[i] >> y[i];
        if (x[i] > y[i]) swap(x[i],y[i]);
    }

    if (y[0] == y[1] && y[1] == y[2] && (x[0] + x[1] + x[2] == y[0]))
    {
        cout << y[0] << endl;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < x[i]; ++j)
            {
                for (int k = 0; k < y[0]; ++k)
                    cout << c[i];
                cout << endl;
            }
        }
        return 0;
    }

    int tt[] = {0, 1, 2};

    do
    {
        int p = tt[0], q = tt[1], r = tt[2];
        swap(x[p], y[p]); swap(x[q], y[q]);
        if (y[q] == y[p] && (x[p] + x[q] == y[r]) && y[p] + x[r] == y[r])
        {
            cout << y[r] << endl;
            for (int i = 0; i < y[p]; ++i)
            {
                for (int j = 0; j < x[p]; ++j)
                    cout << c[p];
                for (int j = 0; j < x[q]; ++j)
                    cout << c[q];
                cout << endl;
            }
            for (int i = 0; i < x[r]; ++i)
            {
                for (int j = 0; j < y[r]; ++j)
                    cout << c[r];
                cout << endl;
            }
            return 0;
        }
        swap(x[p], y[p]);
        if (y[q] == y[p] && (x[p] + x[q] == y[r]) && y[p] + x[r] == y[r])
        {
            cout << y[r] << endl;
            for (int i = 0; i < y[p]; ++i)
            {
                for (int j = 0; j < x[p]; ++j)
                    cout << c[p];
                for (int j = 0; j < x[q]; ++j)
                    cout << c[q];
                cout << endl;
            }
            for (int i = 0; i < x[r]; ++i)
            {
                for (int j = 0; j < y[r]; ++j)
                    cout << c[r];
                cout << endl;
            }
            return 0;
        }
        swap(x[p],y[p]); swap(x[q], y[q]);
        if (y[q] == y[p] && (x[p] + x[q] == y[r]) && y[p] + x[r] == y[r])
        {
            cout << y[r] << endl;
            for (int i = 0; i < y[p]; ++i)
            {
                for (int j = 0; j < x[p]; ++j)
                    cout << c[p];
                for (int j = 0; j < x[q]; ++j)
                    cout << c[q];
                cout << endl;
            }
            for (int i = 0; i < x[r]; ++i)
            {
                for (int j = 0; j < y[r]; ++j)
                    cout << c[r];
                cout << endl;
            }
            return 0;
        }
        swap(x[p],y[p]);
        if (y[q] == y[p] && (x[p] + x[q] == y[r]) && y[p] + x[r] == y[r])
        {
            cout << y[r] << endl;
            for (int i = 0; i < y[p]; ++i)
            {
                for (int j = 0; j < x[p]; ++j)
                    cout << c[p];
                for (int j = 0; j < x[q]; ++j)
                    cout << c[q];
                cout << endl;
            }
            for (int i = 0; i < x[r]; ++i)
            {
                for (int j = 0; j < y[r]; ++j)
                    cout << c[r];
                cout << endl;
            }
            return 0;
        }
    }
    while (next_permutation(tt, tt+3));

    cout << -1;
    return 0;
}
