#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector<int> matrix(25); //Define matrix
	
	for(int i = 0; i < 25; i++) {
		cin >> matrix[i]; //Input matrix
	}
	
	int steps = 0; //Define number of steps
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(matrix[i*5+j] == 1) {
				steps = abs(i-2) + abs(j-2); //Calc number of steps
			}
			else {
				//Do nothing
			}
		}
	}
	
	cout << steps; //Output steps
}