#include <iostream>

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	string a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	
	if(n > 1) {
		for(int i = 0; i < m; i++) {
			bool rep = true;
			while(rep) {
				rep = false;
				for(int j = n-2; j >= 0; j--) {
					if(a[j][i]=='*' && a[j+1][i]=='.') {
						a[j][i] = '.'; a[j+1][i] = '*';
						rep = true;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) cout << a[i] << endl;
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int i; i < t; i++) solve();
}