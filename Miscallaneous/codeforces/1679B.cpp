#include<iostream>
using namespace std;

int main() {
	int n, q; cin >> n >> q;
	int a[n], sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for(int j = 0; j < q; j++) {
		int t; cin >> t;
		if(t == 1) {
			int i, x; cin >> i >> x;
			sum += x-a[i-1];
			a[i-1] = x;
		}
		else if(t == 2) {
			int x; cin >> x;
			sum = n*x;
			for(int i = 0; i < n; i++) {
				a[i] = x;
			}
		}
		cout << sum << endl;
	}
	return 0;
}