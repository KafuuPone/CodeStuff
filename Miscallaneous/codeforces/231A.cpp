#include <iostream>
#include <vector>

using namespace std;

int n = 0; //Number of questions

int main() {
	
	cin >> n; //Input n
	
	int num = 3*n; //Num of elements
	
	vector<int> qvotings(num);
	
	//Input voting results for each question
	for(int i = 0; i < num; i++) {
		cin >> qvotings[i];
	}
	
	int total = 0; //Total questions they will try
	
	for(int i = 0; i < n; i++) {
		int sum = 0; //Total votes for 1 question
		sum = qvotings[i*3] + qvotings[i*3+1] + qvotings[i*3+2];
		if(sum > 1) {
			total++;
		}
		else {
			//Do nothing
		}
	}
	
	cout << total;
	
}