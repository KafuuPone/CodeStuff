#include <iostream>

using namespace std;

int main() {
	int t; cin >> t; //Test cases
	for(int i = 0; i < t; i++) {
		int n; cin >> n; //Number of tasks
		
		//Input start and finish times
		int s[n], f[n];
		for(int j = 0; j < n; j++) {
			cin >> s[j];
		}
		for(int j = 0; j < n; j++) {
			cin >> f[j];
		}
		
		//Solving
		int d[n];
		d[0] = f[0] - s[0];
		for(int j = 1; j < n; j++) {
			if(s[j] < f[j-1]) {
				d[j] = f[j] - f[j-1];
			}
			else {
				d[j] = f[j] - s[j];
			}
		}
		
		//Output
		for(int a : d) cout << a << " ";
		cout << endl;
	}
}