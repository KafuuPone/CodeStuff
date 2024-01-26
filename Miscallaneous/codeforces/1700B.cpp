#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	int n; string x;
	cin >> n >> x;
	string output = "";
	if(x[0] != '9') {
		for(int i = 0; i < n; i++) {
			output += '9'-x[i]+'0';
		}
	}
	else {
		string temp1 = "";
		for(int i = 0; i < n-1; i++) {
			temp1 += '9'-x[i]+'0';
		}
		char one = 10-(x[n-1]-'0')+'0';
		temp1 += one;
		
		string temp2 = "";
		for(int i = 0; i < n; i++) {
			if(i==0 || i>n-3) temp2 += '1';
			else temp2 += '0';
		}
		
		bool carry = false;
		for(int i = n-1; i >= 0; i--) {
			int temp = (temp1[i]-'0')+(temp2[i]-'0')+carry;
			if(temp >= 10) carry = true;
			else carry = false;
			char digit = temp%10 + '0';
			string ins = "";
			ins += digit;
			output.insert(0, ins);
		}
	}
	cout << output << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) solve();
}