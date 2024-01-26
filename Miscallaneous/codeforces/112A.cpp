#include <iostream>
#include <cctype>

using namespace std;

//String inputs
string s1 = "";
string s2 = "";

//Function to convert string to lower case
string strlower(string s) {
	string lower = "";
	for(int i = 0; i < s.length(); i++) {
		lower += tolower(s[i]);
	}
	return lower;
}

int main() {
	cin >> s1 >> s2; //Input both strings
	
	//Convert both strings
	s1 = strlower(s1);
	s2 = strlower(s2);
	
	int len = s1.length(); //Length of string
	
	bool comp_done = false; //Whether comparison is done
	
	int tests = 0; //Current number of tests
	
	int output = 0; //Result output
	
	//Comparison
	while(!comp_done && tests < len) {
		if(int(s1[tests]) > int(s2[tests])) {
			output = 1;
			comp_done = true;
		}
		else if(int(s1[tests]) < int(s2[tests])) {
			output = -1;
			comp_done = true;
		}
		else {
			//Do nothing
		}
		tests++;
	}
	
	cout << output; //Output ans
}