#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long n; cin >> n;
		int sq, cb, sx;
		sq = cb = sx = 1;
		while(pow(sq, 2) <= n) sq++;
		sq--;
		while(pow(cb, 3) <= n) cb++;
		cb--;
		while(pow(sx, 6) <= n) sx++;
		sx--;
		cout << sq+cb-sx << endl;
	}
}