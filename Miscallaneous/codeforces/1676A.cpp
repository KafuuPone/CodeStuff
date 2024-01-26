#include <iostream>

using namespace std;

int main() {
	int t; cin >> t; //Number of tickets
	
	for(int i = 0; i < t; i++) {
		string ticket; cin >> ticket;
		if((int(ticket[0]))+int(ticket[1])+int(ticket[2]) == int(ticket[3])+int(ticket[4])+int(ticket[5])) {
			cout << "YES" << endl;
		}
		else {
			cout<< "NO" << endl;
		}
	}
}