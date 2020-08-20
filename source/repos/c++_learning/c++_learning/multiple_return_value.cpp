#include<iostream>
using namespace std;
void do_math(int a, int b, int& sum, int& sub, int& mul, float& div) {
	sum = a + b;//return sum
	sub = a - b;//return substraction
	mul = a * b;//return multiplication
	div = a / b;//return division
}
int main() {
	int a, b;
	cin >> a >> b;
	float div;
	int sum, sub, mul;
	do_math(a, b, sum, sub, mul, div);
	cout << sum << " " << sub << " " << mul << " " << div << endl;
	return 0;
}