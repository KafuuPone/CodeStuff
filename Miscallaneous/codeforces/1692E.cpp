#include <iostream>

using namespace std;

void solve() {
	int n, s; cin >> n >> s;
	int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
	
	int tempsum = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 1) tempsum++;
	}
	
	int total;
	if(tempsum > s) {
		int left, right;
		left = right = total = 0;
		int i = -1; int j = n;
		while(a[i+1] == 0) {
			i++; left++;
		}
		while(a[j-1] == 0) {
			j--; right++;
		}
		do {
			if(left > right) {
				j--; tempsum--;
				total += right+1;
				if(tempsum == s) break;
				right = 0;
				while(a[j-1] == 0) j--; right++;
			}
			else {
				i++; tempsum--;
				total += left+1;
				if(tempsum == s) break;
				left = 0;
				while(a[i+1] == 0) i++; left++;
			}
		} while(true);
	}
	else if(tempsum == s) total = 0;
	else total = -1;
	
	cout << total << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}