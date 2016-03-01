// méo biết sao sai :'(
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e18;

int N, M, u, v;
ll arr[200009], tree[1000009], lazy[1000009], x;
char s[100];

void build_tree(int node, int a, int b) { // build_tree(1, 0, n-1)
  	if(a > b) return;
  	
  	if(a == b) {
        tree[node] = arr[a];
		return;
	}
	
	build_tree(node << 1, a, (a+b)/2);
	build_tree((node << 1) + 1, 1 + ((a+b) >> 1), b);
	tree[node] = min(tree[node << 1], tree[(node << 1) + 1]);
}

void update_tree(int node, int a, int b, int i, int j, ll value) {  
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
	tree[node] = min(tree[node << 1], tree[(node << 1) + 1]);
}

ll query_tree(int node, int a, int b, int i, int j) {	
	if(a > b || a > j || b < i) return INF;

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
	int res = min(q1, q2);
	
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0);
	// scanf("%d", &N);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
		// scanf("%lld", arr+i);
	build_tree(1, 0, N-1);
	
	// scanf("%d", &M);
	// scanf("%c", &c);
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		// scanf("%[^\n]", s);
		// scanf("%c", &c);
		while (!strlen(s))
			cin.getline(s, 100);
		int type = 0;
		for (int j = 0; s[j]; ++j)
			type += (s[j] == ' ');

		if (type == 1)
		{
			sscanf(s, "%d %d", &u, &v);

			if (u > v)
				printf("%lld\n", min(query_tree(1,0,N-1,u,N-1),
									 query_tree(1,0,N-1,0,v)));
			else
				printf("%lld\n", query_tree(1,0,N-1,u,v));
		}
		else
		{
			sscanf(s, "%d %d %lld", &u, &v, &x);

			if (u > v)
				update_tree(1,0,N-1,u,N-1,x), update_tree(1,0,N-1,0,v,x);
			else
				update_tree(1,0,N-1,u,v,x);
		}
		s[0] = 0;
	}
	return 0;
}