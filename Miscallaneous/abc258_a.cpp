#include<iostream>
using namespace std;

int main() {
	int t; cin >> t;
	int min = t%60; int hr = 21+t/60;
	if(hr > 24) hr %= 24;
	if(hr < 10) cout << 0;
	cout << hr << ':';
	if(min < 10) cout << 0;
	cout << min << endl;
	return 0;
}