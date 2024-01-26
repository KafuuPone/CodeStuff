#include <iostream>

using namespace std;

void solve(int n, string a) {
	string op = "NO";
	int wcount, tRB, noRB;
	wcount = noRB = 1; tRB = 0;
	if(n == 1) {
		if(a[0] == 'W') op = "YES";
	}
	else if(n==2 && a[0]+a[1]=='R'+'B') op = "YES";
	else {
		for(int i = 0; i < n-1; i++) {
			if(a[i] == 'W') {
				if(a[i+1] == 'W') wcount++;
				else noRB = 1;
			}
			else if(a[i+1] == 'W') tRB += noRB;
			else if(a[i]+a[i+1] == 'R'+'B') noRB = 0;
			if(i == n-2) tRB += noRB;
		}
		if(tRB == 0 || wcount == n) op = "YES";
	}
	cout << op << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; string a; 
		cin >> n >> a;
		solve(n, a);
	}
}