#include <bits/stdc++.h>

using namespace std;

int lang[2], point[2], x, y, tt;
string s, t, name[2];
string langList[9] = {"cs", "en", "fr", "de", "hu", "it", "jp", "pl", "es"};
vector<string> move[9][3];

void add(int p, const string& a, const string& b, const string& c) {
	if (a.length() > 0)
		move[p][0].push_back(a);
	if (b.length() > 0)
		move[p][1].push_back(b);
	if (c.length() > 0)
		move[p][2].push_back(c);
}

int main() {

	add(0, "Kamen", "Nuzky", "Papir");
	add(1, "Rock", "Scissors", "Paper");
	add(2, "Pierre", "Ciseaux", "Feuille");
	add(3, "Stein", "Schere", "Papier");
	add(4, "Ko", "Ollo", "Papir");
	add(4, "Koe", "Olloo", "");
	add(5, "Sasso", "Forbice", "Carta");
	add(5, "Roccia", "", "Rete");
	add(6, "Guu", "Choki", "Paa");
	add(7, "Kamien", "Nozyce", "Papier");
	add(8, "Piedra", "Tijera", "Papel");

	while (true) {
		++tt;
		
		for (int i = 0; i < 2; ++i) {
			cin >> s >> name[i];
			point[i] = 0;
			for (int j = 0; j < 9; ++j)
			if (langList[j] == s) {
				lang[i] = j;
				break;
			}
		}

		while (true) {
			cin >> s;
			if (s[0] == '-' || s[0] == '.')
				break;
			cin >> t;

			x = y = -1;
			for (int i = 0; x == -1 && i < 3; ++i) {
				for (int j = 0; j < (int)move[lang[0]][i].size(); ++j)
				if (move[lang[0]][i][j] == s) {
					x = i;
					break;
				}
			}

			for (int i = 0; y == -1 && i < 3; ++i) {
				for (int j = 0; j < (int)move[lang[1]][i].size(); ++j)
				if (move[lang[1]][i][j] == t) {
					y = i;
					break;
				}
			}

			if (x != y) {
				if ((x + 1) % 3 == y) {
					++point[0];
				} else {
					++point[1];
				}
			}
		}

		cout << "Game #" << tt << ":\n";
		for (int i = 0; i < 2; ++i) {
			cout << name[i] << ": " << point[i] << (point[i]==1?" point":" points");
			cout << '\n';
		}

		if (point[0] == point[1]) {
			cout << "TIED GAME\n";
		} else {
			cout << "WINNER: ";
			if (point[0] > point[1])
				cout << name[0] << '\n';
			else
				cout << name[1] << '\n';
		}

		if (s[0] == '.')
			return 0;
		cout << '\n';
	}
	return 0;
}