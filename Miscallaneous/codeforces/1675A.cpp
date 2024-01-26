#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
		int dog = x-a; int cat = y-b;
		if(dog < 0) dog = 0; if(cat < 0) cat = 0;
		if(dog+cat>c) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}