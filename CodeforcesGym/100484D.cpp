#include <bits/stdc++.h>

using namespace std;

struct File {
	string full, name, ext;

	File() {}
	File(char *s) {
		int len = strlen(s);
		int dot = len;
		full = string(s);
		for (int i = 0; i < len; ++i) {
			if (s[i] == '.') {
				dot = i;
				break;
			}
			name.push_back(s[i]);
		}
		for (int i = dot + 1; i < len; ++i)
			ext.push_back(s[i]);
	}
};

int n, m;
File file[1010];
map<string, int> cnt1, cnt2;
vector<int> v;
char buffer[30];

bool cmp1(int x, int y) {
	return cnt1[file[x].name] > cnt1[file[y].name];
}

bool cmp2(int x, int y) {
	return cnt2[file[x].ext] > cnt2[file[y].ext];
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%s", buffer);
		file[i] = File(buffer);
		v.push_back(i);
		++cnt1[file[i].name];
		++cnt2[file[i].ext];
	}

	for (int i = 0; i < m; ++i) {
		if (!(i&1)) {
			sort(v.begin(), v.end(), cmp2);
			while (!v.empty()) {
				int p = v.back();
				if (cnt2[file[p].ext] > 1) {
					break;
				}
				cnt2.erase(file[p].ext);
				if (--cnt1[file[p].name] == 0) {
					cnt1.erase(file[p].name);
				}
				v.pop_back();
			}
		} else {
			sort(v.begin(), v.end(), cmp1);
			while (!v.empty()) {
				int p = v.back();
				if (cnt1[file[p].name] > 1) {
					break;
				}
				cnt1.erase(file[p].name);
				if (--cnt2[file[p].ext] == 0) {
					cnt2.erase(file[p].ext);
				}
				v.pop_back();
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", (int)v.size());
	for (int i = 0; i < (int)v.size(); ++i) {
		printf("%s\n", file[v[i]].full.c_str());
	}
	return 0;
}