#include <iostream>

using namespace std;

void solve() {
	int n; cin >> n; //Number of elements
	
	//Input array
	int a[n];
	for(int& i : a) cin >> i;
	
	int output = 0;
	
	//Solving
	for(int i = n-2; i>=0 && a[i]!=0; i--) {
		if(a[i] >= a[i+1]) {
			a[i] /= 2;
			output++;
			i++;
		}
	}
	
	//Checking
	for(int i = 0; i < n-1; i++) {
		if(a[i] >= a[i+1]) {
			output = -1;
			break;
		}
	}
	
	cout << output << endl;
}

int main() {
	int t; cin >> t; //Test cases
	for(int i = 0; i < t; i++) {
		solve();
	}
}