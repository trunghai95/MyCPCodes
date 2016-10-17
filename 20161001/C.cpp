#include <bits/stdc++.h> 

using namespace std; 

int n ; 
vector <int > ed[1000]; 
bool mark[1000], dd[1000]; 
int num[1000], low[1000], cnt; 
map <string, int> M[1000] ;
string S[1000] , native[1000]; 
stack <int > st ; 
int ncompo , cou[1000]; 
string Str  ; 

void build_graph() { 
	for (int i = 1; i <= n; i++) 
		{ 
			for (int j = 1 ; j <= n; j++) 
				if (i != j && M[j][native[i]]) 
					ed[i].push_back(j); 
		}
}

void visit(int u) { 

	dd[u] = 1; 
	low[u] = num[u] = ++cnt; 
	st.push(u); 
	for (int i  = 0 ; i < ed[u].size() ; i++) { 
		int v = ed[u][i]; 
		if (mark[v] ) continue ; 
		if (!dd[v]) { 
			dd[v] = 1; 
			visit(v); 
			low[u] = min(low[u], low[v]); 
		} else { 
			low[u] = min(low[u]  , num[v]); 
		}
	}
	if (low[u] == num[u]) { 
		ncompo ++; 
		while (st.top() != u) { 
			mark[st.top()] = 1; 
			cou[ncompo]++; 
			st.pop(); 
		}
		mark[u] = 1; 
		cou[ncompo]++; 
		st.pop();
	}
}

int main () { 
	cin >> n ; 
	for (int i = 1 ;  i <= n ; i++) { 
		cin >> S[i] >> native[i]; 
		M[i][native[i]] = 1;
		getline(cin , Str); 
		stringstream sstr(Str);

		while (sstr >> Str) {
			M[i][Str] = 1; 
		}
	}



	build_graph(); 

	for (int i = 1 ;  i <= n ; i++) 
			if (!dd[i]) 
				visit(i); 

	int maxr  = 0 ; 
	for (int i = 1;  i<= ncompo ; i++)  
		maxr = max(maxr , cou[i]); 
	cout << n - maxr ;  
}