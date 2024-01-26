#include <iostream>

using namespace std;

void solve() {
	long long n, m; cin >> n >> m;
	cout << m*(m+1)/2 + m*n*(n+1)/2 - m << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}