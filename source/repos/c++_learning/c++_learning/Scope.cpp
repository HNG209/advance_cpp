#include<iostream>
using namespace std;
int main() {
	int x, y, z, a, b, c;
	c = 20;
	{
		//empty scope
		int a, b, c;
		a = 10;
		b = 5;
		c = 9;
		cout << "scope 1:" <<  c << endl;
		{
			//another empty scope
			int a, b, c;
			c = 15;
			cout << "scope 2:" << c << endl;
		}
	}
	cout << "scope 3:" << c << endl;
	return 0;
}