#include <iostream>

using namespace std;

void compare();
int value(string);

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++)
        compare();
    return 0;
}

void compare()
{
    string a, b; cin >> a >> b;
    if(value(a) > value(b))
        cout << '>' << endl;
    else if(value(a) < value(b))
        cout << '<' << endl;
    else
        cout << '=' << endl;
}

int value(string s)
{
    switch(s[s.length()-1])
    {
    case 'S':
        return -s.length();
    case 'M':
        return 0;
    case 'L':
        return s.length();
    }
}
