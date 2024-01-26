#include <iostream>

using namespace std;

void solve() {
	string s; char c; cin >> s >> c;
	int n = s.length();
	string output = "NO";
	for(int i = 0; i <= (n-1)/2; i++) {
		if(s[2*i] == c) {
			output = "YES";
			break;
		}
	}
	cout << output << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}