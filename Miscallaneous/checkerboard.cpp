#include<iostream>
using namespace std;

int main() {
	int num; char OX;
	cin >> num >> OX;
	bool circle = (OX == 'O');
	bool fcircle = circle;
	for(int i = 0; i < num; i++) {
		circle = fcircle;
		for(int j = 0; j < num; j++) {
			if(circle) cout << 'O';
			else cout << 'X';
			circle = !circle;
		}
		cout << endl;
		fcircle = !fcircle;
	}
}