#include <iostream>

using namespace std;

void solve() {
	int a, b, s; cin >> a >> b;
	if(a == 0) s = 1;
	else s = a+2*b+1;
	cout << s << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0;i < t; i++) solve();
}