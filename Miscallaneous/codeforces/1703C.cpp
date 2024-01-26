#include<iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		int l; cin >> l;
		string m; cin >> m;
		for(int j = 0; j < l; j++) {
			if(m[j] == 'U') a[i]--;
			else a[i]++;
			if(a[i] == 10) a[i] = 0;
			if(a[i] == -1) a[i] = 9;
		}
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}