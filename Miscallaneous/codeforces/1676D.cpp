#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t; //Number of tests
	
	for(int i = 0; i < t; i++) {
		int n; cin >> n; //Number of rows
		int m; cin >> m; //Number of cols
		//Input chessboard
		vector<vector<int>> s;
		for(int j = 0; j < n; j++) {
			vector<int> v;
			for(int k = 0; k < m; k++) {
				int e; cin >> e;
				v.push_back(e);
			}
			s.push_back(v);
		}
		
		//Max sum for bishop
		int max = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				//Sum of bishop moves at i, j
				int sum = s[i][j];
				for(int c = 1; (c < n-i)&&(c < m-j); c++) {
					sum += s[i+c][j+c];
				}
				for(int c = 1; (c <= i)&&(c < m-j); c++) {
					sum += s[i-c][j+c];
				}
				for(int c = 1; (c <= i)&&(c <= j); c++) {
					sum += s[i-c][j-c];
				}
				for(int c = 1; (c < n-i)&&(c <= j); c++) {
					sum += s[i+c][j-c];
				}
				
				//Determine max
				if(sum > max) {
					max = sum;
				}
			}
		}
		cout << max << endl;
	}
	
	return 0;
}