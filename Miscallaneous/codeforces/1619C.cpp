#include <iostream>

using namespace std;

void solve() {
	string a, b; cin >> a >> b;
	int x, y;
	x = a.length(); y = b.length();
	int i = x-1; int j = y-1; string c = "";
	while(j >= 0) {
		if(i < 0) {
			c.insert(0, 1, b[j]);
			j--;
		}
		else {
			if(b[j] >= a[i]) {
				char temp = b[j]-a[i]+'0';
				c.insert(0, 1, temp);
				j--; i--;
			}
			else if(j!=0 && b[j-1]=='1') {
				char temp = 10+b[j]-a[i]+'0';
				c.insert(0, 1, temp);
				j -= 2; i--;
			}
			else {
				c = "-1";
				break;
			}
		}
	}
	if(i >= 0) c = "-1";
	int z = c.length();
	string output = ""; bool start = false;
	for(int n = 0; n < z; n++) {
		if(c[n] != '0') start = true;
		if(start) output += c[n];
	}
	if(output.length() == 0) output = "0";
	cout << output << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}