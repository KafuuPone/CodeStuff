#include<iostream>
using namespace std;

void solve() {
	long long n; cin >> n;
	long long min, max;
	min = max = -1;
	if(n%2 == 0) {
		for(int x = 0; x <= n/4; x++) {
			if((n-4*x)%6 == 0) {
				min = x + (n-4*x)/6;
				break;
			}
		}
		for(int y = 0; y <= n/6; y++) {
			if((n-6*y)%4 == 0) {
				max = y + (n-6*y)/4;
				break;
			}
		}
		if(min==-1 || max==-1) cout << -1 << endl;
		else cout << min << " " << max << endl;
	}
	else cout << -1 << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
	return 0;
}