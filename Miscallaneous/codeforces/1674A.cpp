#include <iostream>

using namespace std;

int main() {
	int t; cin >> t; //Num of cases
	int x; int y;
	
	for(int i = 0; i < t; i++) {
	    int a = 0; int b = 0;
		cin >> x >> y;
		if(y%x == 0) {
			a = 1;
			b = y/x;
		}
		cout << a << " " << b << endl;
	}
}