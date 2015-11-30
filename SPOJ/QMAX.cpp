#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int arr[50010];
int tree[200010];
int lazy[200010];

void build_tree(int node, int a, int b) { // build_tree(1, 0, n-1)
  	if(a > b) return;

  	if(a == b) {
        tree[node] = arr[a];
		return;
	}

	build_tree(node << 1, a, (a+b)/2);
	build_tree((node << 1) + 1, 1 + ((a+b) >> 1), b);
	tree[node] = max(tree[node << 1], tree[(node << 1) + 1]);
}

void update_tree(int node, int a, int b, int i, int j, int value) {
  	if (lazy[node]) {
   		tree[node] += lazy[node];

		if(a != b) {
			lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
		}
   		lazy[node] = 0;
  	}

	if(a > b || a > j || b < i)
		return;

  	if(a >= i && b <= j) {
        tree[node] += value;

		if(a != b) {
			lazy[node << 1] += value;
			lazy[(node << 1) + 1] += value;
		}
        return;
	}

	update_tree(node << 1, a, (a+b)/2, i, j, value);
	update_tree((node << 1) + 1, ((a+b) >> 1) + 1, b, i, j, value);
	tree[node] = max(tree[node << 1], tree[(node << 1) + 1]);
}

int query_tree(int node, int a, int b, int i, int j) {
	if(a > b || a > j || b < i) return -inf;

	if(lazy[node]) {
		tree[node] += lazy[node];

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
	int res = max(q1, q2);

	return res;
}

int main()
{
    int n, m, q;
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v, k; i < m; ++i)
    {
        scanf("%d %d %d", &u, &v, &k);
        update_tree(1, 1, n, u, v, k);
    }
    scanf("%d", &q);
    for (int i = 0, u, v; i < q; ++i)
    {
        scanf("%d %d", &u, &v);
        printf("%d\n", query_tree(1, 1, n, u, v));
    }
    return 0;
}
