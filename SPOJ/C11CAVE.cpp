#include <bits/stdc++.h>

using namespace std;

const int MAXH = 5e5;
int arr[MAXH + 1];
int tree[MAXH*4 + 1];
int lazy[MAXH*4 + 1];

void build_tree(int node, int a, int b) { // build_tree(1, 0, n-1)
  	if(a > b) return;

  	if(a == b) {
    		tree[node] = arr[a];
		return;
	}

	build_tree(node << 1, a, (a+b)/2);
	build_tree((node << 1) + 1, 1 + ((a+b) >> 1), b);
	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void update_tree(int node, int a, int b, int i, int j, int value) {
  	if(lazy[node] != 0) {
   		tree[node] += lazy[node]*(b - a + 1);

		if(a != b) {
			lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
		}
   		lazy[node] = 0;
  	}

	if(a > b || a > j || b < i)
		return;

  	if(a >= i && b <= j) {
        tree[node] += value*(b - a + 1);

		if(a != b) {
			lazy[node << 1] += value;
			lazy[(node << 1) + 1] += value;
		}
        return;
	}

	update_tree(node << 1, a, (a+b)/2, i, j, value);
	update_tree((node << 1) + 1, ((a+b) >> 1) + 1, b, i, j, value);

	tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int query_tree(int node, int a, int b, int i, int j) {
	if(a > b || a > j || b < i) return 0;

	if(lazy[node] != 0) {
		tree[node] += lazy[node]*(b - a + 1);

		if(a != b) {
			lazy[node << 1] += lazy[node];
			lazy[(node << 1) + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(a >= i && b <= j)
		return tree[node];

	int q1 = query_tree(node << 1, a, (a+b) >> 1, i, j);
	int q2 = query_tree((node << 1) + 1, ((a+b) >> 1) + 1, b, i, j);
	int res = q1 + q2;

	return res;
}

int n, h;

int main()
{
    scanf("%d %d", &n, &h);
    for (int i = 1, tmp; i <= n; ++i)
    {
        scanf("%d", &tmp);

        if (i&1)
            update_tree(1, 1, h, 1, tmp, 1);
        else
            update_tree(1, 1, h, h - tmp + 1, h, 1);
    }

    int res = 2e9, cnt = 0;

    for (int i = 1; i <= h; ++i)
    {
        int tmp = query_tree(1, 1, h, i, i);
        if (tmp < res)
        {
            cnt = 1;
            res = tmp;
        }
        else if (tmp == res) ++cnt;
    }

    printf("%d %d", res, cnt);
    return 0;
}

