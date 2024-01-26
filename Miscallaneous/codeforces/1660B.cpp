#include <iostream>

using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int amax = 0; int index;
	for(int i = 0; i < n; i++) {
		if(a[i] > amax) {
			amax = a[i];
			index = i;
		}
	}
	string output = "NO";
	if(a[0]==1 && n==1) output = "YES";
	else {
		for(int i = 0; i < n; i++) {
			if(i == index) continue;
			if(amax-a[i] < 2) {
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