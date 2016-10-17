#include <bits/stdc++.h> 

using namespace std ; 

int tcase ,  n , m ; 
string  S; 


bool dp[3][510][510] ; 


void solve() { 
	for (int i = 0 ; i <= 500; i++)  for (int j = 0 ; j <= 500; j++) 
		{ 
			dp[0][i][j] = 0; 
			dp[1][i][j] = 0; 
		}


	dp[0][1][1] = 0; 
	dp[1][1][1] = 0; 


	for (int i = 1; i <= 500 ; i++) 
		for (int j = 1; j <= 500; j++) 
			if (i != 1 || j != 1) { 
				// cout << "ok" <<endl ;
				for (int k =  2 ;  k <= i ; k ++ ) 
					{ 
						if (!dp[1][k-1][j] && !dp[1][i - ( k- 1)][j]) 
						dp[0][i][j] = 1; 
				} 

				for (int k = 2;  k <= j ; k++)  
					if (!dp[0][i][k-1] && !dp[0][i][j - (k -1)])
					 
				{ 
					//if (i == 2 && j == 2) cout << k <<' '<< dp[0][i][k-1] <<' '<<dp[0][i][j - (k -1)] <<endl; 
					dp[1][i][j] = 1;
				}


			}

}

int main() 
{ 

		solve() ; 
	cin >> tcase ; 
	while (tcase -- ) { 
		cin >> n >> m  >>  S; 
		swap(n, m);
		if (S[0] == 'H' && dp[0][n][m]) cout << "Harry can win\n"; 
		if (S[0] == 'H' && !dp[0][n][m]) cout << "Harry cannot win\n";

		if (S[0] == 'V' && dp[1][n][m]) cout << "Vicky can win\n"; 
		if (S[0] == 'V' && !dp[1][n][m]) cout << "Vicky cannot win\n";
	}

}