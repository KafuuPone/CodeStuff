#include <iostream>
#include <vector>

using namespace std;

int n = 0;
int x = 0;

int main() {
	cin >> n;
	
	vector<string> sts(n);//Vector of statements
	
	for(int i = 0; i < n; i++) {
		cin >> sts[i];
	}
	
	for(int i = 0; i < n; i++) {
		if(sts[i] == "++X" || sts[i] == "X++") {
			x++;
		}
		else if(sts[i] == "--X" || sts[i] == "X--") {
			x--;
		}
		else {
			//Do nothing
		}
	}
	
	cout << x;
}