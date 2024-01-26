#include <iostream>

using namespace std;

void solve() {
	string s; cin >> s;
	string output;
	int n = s.length();
	if(n%2 != 0) output = "NO";
	else {
		output = "YES";
		for(int i = 0; i < n/2; i++) {
			if(s[i] != s[i+n/2]) output = "NO";
		}
	}
	cout << output << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}