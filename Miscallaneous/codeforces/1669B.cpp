#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int a[n];
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		sort(a, a+n);
		int output = -1;
		for(int j = 0; j < n-2; j++) {
			if(a[j]==a[j+1] && a[j+1]==a[j+2]) output = a[j];
		}
		cout << output << endl;
	}
}