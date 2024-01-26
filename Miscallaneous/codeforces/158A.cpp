#include <iostream>
#include <vector>

using namespace std;

int n = 0; //Number of contestants
int k = 0; //kth place

int main() {
	cin >> n >> k; //Input n, k
	
	vector<int> score(n);
	
	for(int i = 0; i < n; i++) {
		cin >> score[i];
	}
	
	int sum = 0; //Number of people >= kth's score
	
	//Calculate sum
	for(int i = 0; i < n; i++) {
		if(score[i] >= score[k-1] && score[i] > 0) {
			sum++; //If score is >= kth's score, increase by 1
		}
		else {
			//Do nothing
		}
	}
	
	cout << sum;
}