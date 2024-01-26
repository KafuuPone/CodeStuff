#include <iostream>

using namespace std;

int main() {
	int t; cin >> t; //Test cases
	for(int j = 0; j < t; j++) {
		int n, k; cin >> n >> k; //Length of strip, length of black needed
		string s; cin >> s; //Strip
		int b = 0; //Number of black spots in k
		
		//Initialize
		for(int i = 0; i < k; i++) {
			if(s[i] == 'B') b++;
		}
		
		//Checking whole strip, while finding maximum
		int maxb = b;
		for(int i = 1; i <= n-k; i++) {
			if(s[i-1] == 'B') b--;
			if(s[i+k-1] == 'B') b++;
			if(b > maxb) maxb = b;
		}
		
		cout << k - maxb << endl;
	}
}