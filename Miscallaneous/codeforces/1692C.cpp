#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		//Input initial chessboard
		string a[8];
		for(int j = 0; j < 8; j++) {
			cin >> a[j];
		}
		
		int r, c;
		bool b = true;
		for(int j = 1; j < 7 && b; j++) {
			for(int k = 1; k < 7 && b; k++) {
				if((a[j-1][k-1] == '#') && (a[j+1][k-1] == '#') && (a[j+1][k+1] == '#') && (a[j-1][k+1] == '#')) {
					r = j+1;
					c = k+1;
					b = false;
				}
			}
		}
		
		cout << r << " " << c << endl;
	}
	return 0;
}