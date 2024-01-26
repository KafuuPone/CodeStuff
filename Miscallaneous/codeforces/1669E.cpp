#include <iostream>

using namespace std;
typedef long long ll;

void record(int n, int list[11][11]) {
	for(int i = 0; i < 11; i++) {
		for(int j = 0; j < 11; j++) list[i][j] = 0;
	}
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		int row = s[0]-'a'; int col = s[1]-'a';
		list[row][col]++;
	}
}

ll solve(int list[11][11]) {
	ll op = 0;
	//Row sum
	for(int i = 0; i < 11; i++) {
		int rowsum = 0;
		for(int j = 0; j < 11; j++) rowsum += list[i][j];
		op += rowsum*(rowsum-1)/2;
	}
	//Col sum
	for(int j = 0; j < 11; j++) {
		int colsum = 0;
		for(int i = 0; i < 11; i++) colsum += list[i][j];
		op += colsum*(colsum-1)/2;
	}
	//Repeats
	for(int i = 0; i < 11; i++) {
		for(int j = 0; j < 11; j++) {
			int num = list[i][j];
			op -= num*(num-1);
		}
	}
	return op;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int list[11][11];
		record(n, list);
		cout << solve(list) << endl;
	}
}