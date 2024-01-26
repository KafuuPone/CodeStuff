#include <iostream>

using namespace std;

void solve() {
	int a, b, c; cin >> a >> b >> c;
	bool ayes, byes, cyes;
	ayes = 2*b-c>0 && (2*b-c)%a==0;
	byes = (a+c)%2==0 && (a+c)/2>0 && ((a+c)/2)%b==0;
	cyes = 2*b-a>0 && (2*b-a)%c==0;
	if(ayes || byes || cyes) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}