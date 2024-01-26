#include <iostream>

using namespace std;

int main() {
	int t; cin >> t; //Test cases
	for(int i = 0; i < t; i++) {
		int n; cin >> n; //Total num of blocks
		int s, g, b; //Silver, gold, bronze
		switch(n%3) {
			case 0:
				s = n/3; g = s+1; b = s-1;
				break;
			case 1:
				s = n/3; g = s+2; b = s-1;
				break;
			case 2:
				s = n/3+1; g = s+1; b = s-2;
				break;
		}
		cout << s << " " << g << " " << b << endl;
	}
}