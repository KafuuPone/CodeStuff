#include <iostream>

using namespace std;

void solve() {
	int l, r, a; cin >> l >> r >> a;
	int y;
	if(l/a==r/a || (r+1)%a==0) y = (r/a)+(r%a);
	else y = (r/a)+a-2;
	cout << y << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}