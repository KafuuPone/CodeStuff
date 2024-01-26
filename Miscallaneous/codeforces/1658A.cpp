#include<iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	string a; cin >> a;
	int sum = 0;
	for(int i = 0; i < n-1; i++) {
		if(a[i]=='0' && a[i+1]=='0') sum += 2;
	}
	for(int i = 1; i < n-1; i++) {
		if(a[i-1]=='0' && a[i]=='1' && a[i+1]=='0') sum++;
	}
	cout << sum << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
	return 0;
}