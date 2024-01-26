#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int r; cin >> r;
		cout << "Division " << 1+(r<1900)+(r<1600)+(r<1400) << endl;
	}
}