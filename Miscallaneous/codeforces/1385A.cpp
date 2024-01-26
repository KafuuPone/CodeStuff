#include <bits/stdc++.h>

using namespace std;

int t = 0; //Number of tests, t
int x = 0;
int y = 0;
int z = 0;

void calc(int X, int Y, int Z) {
	//Arrange inputs
	vector<int> v = {X, Y, Z};
	
	sort(v.begin(), v.end(), greater<int>());
	
	X = v[0];
	Y = v[1];
	Z = v[2];
	
	//The real calculations
	if(X==Y && X>Z) {
		cout << "YES\n";
		cout << X << " " << Z << " " << Z << "\n";
	}
	else if(X==Y && Y==Z) {
		cout << "YES\n";
		cout << X << " " << X << " " << X << "\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	cin >> t; //Input t
	
	for(int i = 0; i < t; i++) {
		cin >> x >> y >> z; //Input x, y, z
		calc(x, y, z);
	}
}