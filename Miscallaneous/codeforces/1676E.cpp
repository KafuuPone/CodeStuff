#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t; //Number of tests
	for(int i = 0; i < t; i++) {
		int n; cin >> n; //Number of candies
		int q; cin >> q; //Number of queries
		
		//Input a1 to an
		int a[n];
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		
		//Rearrange array in desc order
		sort(a, a+n, greater<int>());
		
		//Output min candies per query
		for(int j = 0; j < q; j++) {
			int x; cin >> x; //Input x, min
			int m = 0; //Min number of candies
			int sum = 0; //Current sum of a
			while(sum<x && m < n) {
				sum += a[m];
				min++;
			}
			if(sum<x || m>n) {
				min = -1;
			}
			cout << m << endl;
		}
	}
}