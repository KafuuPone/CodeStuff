#include <iostream>

using namespace std;

int main() {
	int t; cin >> t; //Test cases
	for(int i = 0; i < t; i++) {
		int n; cin >> n; //Size of arrays
		
		//Input arrays
		int a[n], b[n];
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		for(int j = 0; j < n; j++) {
			cin >> b[j];
		}
		
		//Computing maximum for both arrays
		int amax = 0;
		for(int j = 0; j < n; j++) {
			if(a[j] > amax) amax = a[j];
		}
		int bmax = 0;
		for(int j = 0; j < n; j++) {
			if(b[j] > bmax) bmax = b[j];
		}
		
		do {
			//Subtracting
			int d = amax - bmax;
			if(d < 0) {
				cout << "NO" << endl;
				break;
			}
			for(int j = 0; j < n; j++) {
				if(a[j] - d < 0) {
					a[j] = 0;
					continue;
				}
				a[j] = a[j] - d;
			}
			
			//Comparing
			string output = "YES";
			for(int j = 0; j < n; j++) {
				if(a[j] != b[j]) {
					output = "NO";
					break;
				}
			}
			
			//Output
			cout << output << endl;
		} while(false);
	}
}