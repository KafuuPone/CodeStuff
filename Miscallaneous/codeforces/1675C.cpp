#include <iostream>

using namespace std;

struct list {
	int one;
	int zero;
	int q;
}; //To record number of symbols

void solve() {
	string s; cin >> s; //String input
	int l = s.length(); //String length
	int n = 0; //Number of suspects
	
	//Initialize back, front
	list back, front;
	back.one = back.zero = back.q = 0;
	front.one = front.zero = front.q = 0;
	for(int i = 1; i < l; i++) {
		int temp = s[i];
		front.one += temp=='1';
		front.zero += temp=='0';
		front.q += temp=='?';
	}
	
	//Detection for 1st person
	n += front.one==0;
	
	//Detection for rest
	for(int i = 1; i < l; i++) {
		int prev = s[i-1];
		int curr = s[i];
		back.one += prev=='1';
		back.zero += prev=='0';
		back.q += prev=='?';
		front.one -= curr=='1';
		front.zero -= curr=='0';
		front.q -= curr=='?';
		n += (back.zero+front.one)==0;
	}
	
	cout << n << endl;
}

int main() {
	int t; cin >> t; //Test cases
	for(int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}