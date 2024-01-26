#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for(int j = 0; j < t; j++) {
		int n; cin >> n; //Length of array
		int a[n];
		for(int& i : a) cin >> i;
		
		sort(a, a+n);
		
		int num = 1; //Length of final array
		for(int i = 1; i < n; i++) {
			if(a[i] != a[i-1]) {
				num++;
			}
		}
		
		if((n-num)%2 == 1) {
			num -= 1;
		}
		
		cout << num << endl;
	}
}