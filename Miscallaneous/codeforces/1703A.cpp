#include<iostream>
using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string o; cin >> o;
		if(!((o[0]=='Y' || o[0]=='y')&(o[1]=='E' || o[1]=='e')&(o[2]=='S' || o[2]=='s'))) o = "NO";
		cout << o << endl;
	}
}