#include <iostream>

using namespace std;

void solve() {
	int n; cin >> n;
	int temp, max, min;
	cin >> temp;
	max = min = temp;
	for(int i = 0; i < n-1; i++) {
		cin >> temp;
		if(temp > max) max = temp;
		if(temp < min) min = temp;
	}
	cout << max-min << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}