#include <iostream>
#include <cmath>

using namespace std;

//Difference between 2 strings
int diff(string a, string b, int m) {
	int diff = 0;
	for(int i = 0; i < m; i++) {
		diff += abs(a[i] - b[i]);
	}
	return diff;
}

//Comparison between n strings
int comp(int n, int m) {
	string l[n];
	
	//Input all strings
	for(int i = 0; i < n; i++) {
		cin >> l[i];
	}
	
	int min = diff(l[0], l[1], m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j > i && diff(l[i], l[j], m) < min) {
				min = diff(l[i], l[j], m);
			}
		}
	}
	
	return min;
}

int main() {
	int t; cin >> t; //Number of test cases
	
	for(int i = 0; i < t; i++) {
		int n; cin >> n; //Number of strings
		int m; cin >> m; //Length of string
		cout << comp(n, m) << endl;
	}
}