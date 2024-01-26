#include <iostream>

using namespace std;

int main() {
	int t; cin >> t; //Test cases
	for(int i = 0; i < t; i++) {
		int n; cin >> n; //Length of array
		//Input array
		int a[n];
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		//Solving
		string output = "YES";
		int even, odd;
		even = a[0]%2; odd = a[1]%2;
		for(int j = 2; j < n; j++) {
			if(j%2 == 0) {
				if(a[j]%2 != even) {
					output = "NO"; break;
				}
			}
			else {
				if(a[j]%2 != odd) {
					output = "NO"; break;
				}
			}
		}
		cout << output << endl;
	}
}