#include<iostream>
#include <algorithm>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	if(n%2 == 0) {
		sort(a, a+n);
		int b[n];
		for(int i = 0; i < n; i++) {
			if(i%2 == 1) b[i] = a[(n+i)/2];
			else b[i] = a[i/2];
		}
		string output = "YES";
		for(int i = 1; i < n-1; i+=2) {
			if(b[i] <= b[i+1]) {
				output = "NO";
				break;
			}
		}
		cout << output << endl;
		if(output[0] == 'Y') {
			for(int i = 0; i < n; i++) cout << b[i] << " ";
			cout << endl;
		}
	}
	else cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
	return 0;
}