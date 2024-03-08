#include<bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
int n, m;
int p[N];
void solve() {
	p[0] = 1;
	for (int  i = 1; i < 200; i++)
		p[i] = p[i - 1] * 256 % m;
}
int solve_1(string s) {
	int hash = 0, k = s.size();
	for (int i = 0; i < k; i++)
		hash = (hash + p[k - (i + 1)] * s[i]) % m; 
	return hash;
}
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	solve();
	string s;
	while (n--) {
		cin >> s;
		cout << solve_1(s) << '\n';
	}
}
