#include <iostream>

using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool repeat = true;
	int wl, wr, ts, sum; sum = 0;
	int i, j; i = -1; j = n;
	if(n == 1) repeat = false;
	while(repeat) {
		i++; j--;
		wl = a[i]; wr = a[j]; ts = 2;
		while(wr!=wl && repeat) {
			while(wr<wl && repeat) {
				j--;
				if(i < j) {
					wr += a[j];
					ts++;
				}
				else repeat = false;
			}
			while(wl<wr && repeat) {
				i++;
				if(i < j) {
					wl += a[i];
					ts++;
				}
				else repeat = false;
			}
		}
		if(wr == wl) {
			sum += ts;
			if(j-i-1 < 2) repeat = false;
		}
	}
	cout << sum << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}