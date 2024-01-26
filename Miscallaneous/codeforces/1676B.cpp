#include <iostream>

using namespace std;

void calc(int n) {
	int a1; cin >> a1;
	
	int min = a1;
	int sum = a1;
	
	for(int i = 0; i < n-1; i++) {
		int ai; cin >> ai;
		sum += ai;
		if(ai < min) {
			min = ai;
		}
	}
	
	cout << sum - n*min << endl;
}

int main() {
	int t; cin >> t; //Input t
	
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		calc(n);
	}
}