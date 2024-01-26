#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	
	for(int i = 0; i < t; i++) {
		string word; cin >> word;
		int a = int(word[0]) - 96;
		int b = int(word[1]) - 96;
		int oind = 26*(a-1)+b; //Old index
		int index = oind - (oind+26)/27; //Index
		cout << index << endl;
	}
}