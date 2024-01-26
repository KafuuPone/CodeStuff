#include <iostream>
#include <vector>

using namespace std;

int n = 0; //Number of words

int main() {
	
	cin >> n; //Input n
	vector<string> words(n); //Create vector for inputs
	
	for(int i = 0; i < n; i++) {
		cin >> words[i]; //Input each element of vector
	}
	
	for(int i = 0; i < n; i++) {
		//Words longer than 10 chars
		if(words[i].length() > 10) {
			string longword = words[i];
			cout << longword[0] << longword.length() - 2 << longword[longword.length() - 1] << "\n";
		}
		//Words shorter than 10 chars
		else {
			cout << words[i] << "\n";
		}
	}
}