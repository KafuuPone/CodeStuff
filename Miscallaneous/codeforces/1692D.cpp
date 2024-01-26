#include <iostream>

using namespace std;

struct time {
	int hr;
	int min;
};

//Add time to min
time addt(time t, int m) {
	time newt;
	newt.hr = (t.hr+(t.min+m)/60)%24;
	newt.min = (t.min+m)%60;
	return newt;
}

//Calculate whether time is palindrome
bool palin(time t) {
	int revm = t.min/10 + (t.min%10)*10; //Reversed min
	if(revm == t.hr) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s; //Time input
		time input;
		input.hr = (s[0]-48)*10+(s[1]-48);
		input.min = (s[3]-48)*10+(s[4]-48);
		
		int x; cin >> x; //Minutes
		time updt = input; //Updated time
		int sum = 0; //Times of palindrome
		
		//Calculation
		do {
			if(palin(updt)) {
				sum++;
			}
			updt = addt(updt, x);
		} while(updt.hr != input.hr || updt.min != input.min);
		
		cout << sum << endl;
	}
	return 0;
}