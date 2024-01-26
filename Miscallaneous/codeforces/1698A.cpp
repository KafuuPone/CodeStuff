#include <iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	int temp;
	for(int i = 0; i < n; i++) {
		cin >> temp;
	}
	cout << temp << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
	return 0;
}