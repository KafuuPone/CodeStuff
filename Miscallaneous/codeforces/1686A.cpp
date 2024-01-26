#include <iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n], sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	string output = "NO";
	if(sum%n == 0) {
		int av = sum/n;
		for(int i = 0; i < n; i++){
			if(av == a[i]) {
				output = "YES";
				break;
			}
		}
	}
	cout << output << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}