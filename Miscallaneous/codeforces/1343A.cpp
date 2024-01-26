#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t; cin >> t;
	for(int i; i < t; i++) {
		int n, k; cin >> n;
		k = 2;
		while(n%int(pow(2, k)-1) != 0) k++;
		cout << n/int(pow(2, k)-1) << endl;
	}
}