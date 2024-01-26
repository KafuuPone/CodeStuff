#include <iostream>
#include <cmath>

using namespace std;

//Check whether string has 'a' character
bool check(string t) {
	bool output = false;
	for(int j = 0; j < t.length(); j++) {
		if(t[j] == 'a') {
			output = true;
			break;
		}
	}
	return output;
}

int main() {
	int q; cin >> q; //Num of test cases
	
	for(int i = 0; i < q; i++) {
		string s; cin >> s;
		string t; cin >> t;
		long long int r = 0; //Result
		if(t == "a") {
			r = 1;
		}
		else if(check(t)) {
			r = -1;
		}
		else {
			r = pow(2, s.length());
		}
		cout << r << endl;
	}
}