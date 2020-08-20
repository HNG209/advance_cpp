#include<iostream>
#include<vector>
#include<exception>
using namespace std;
float divide(float a, float b) {
	if (b == 0) {
		throw std::exception("cannot divided by 0");
	}
	else {
		return a / b;
	}
}
int main() {
	try
	{
		int a, b;
		cin >> a >> b;
		cout << divide(a, b) << endl;
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
	catch (...) {
		cout << "other error" << endl;
	}
	return 0;
}