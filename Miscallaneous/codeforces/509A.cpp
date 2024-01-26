#include <iostream>
#include <vector>
 
using namespace std;
 
int n = 0;

int main() {
	cin >> n;
	
	vector<int> matr(n*n); //Create a nxn matrix
	
	//Initial matrix with 1st row and column
	for(int i = 0; i < n*n; i++) {
		int col = i % n;
		int row = i / n;
		if(col == 0 || row == 0) {
			matr[i] = 1;
		}
	}
	
	//Fill in rest of it
	for(int row = 1; row < n; row++) {
		for(int col = 1; col < n; col++) {
			matr[row*n+col] = matr[(row-1)*n+col] + matr[row*n+(col-1)];
		}
	}
	
	cout << matr[n*n-1]; //Output result
}