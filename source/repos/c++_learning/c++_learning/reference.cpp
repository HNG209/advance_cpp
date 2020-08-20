#include<iostream>
using namespace std;
void do_sum(float& sum) {//truyền tham chiếu
	float a, b;
	cout << "enter a:";
	cin >> a;
	cout << "enter b:";
	cin >> b;
	sum = a + b;
}
void do_Sum(float* sum) {//truyền con trỏ
	float a;
	float b;
	cout << "enter a:";
	cin >> a;
	cout << "enter b:";
	cin >> b;
	*sum = a + b;
}
int main() {
	float sum;
	do_Sum(&sum);
	cout << "sum is " << sum << endl;
	return 0;
}