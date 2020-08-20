#include<iostream>
using namespace std;
class A {
private:
	int a, b, c;
public:
	A() : a(0),b(0),c(0) {

	}
	void print() {
		cout << a << " " << b << " " << c << endl;
	}
	~A() {

	}
	friend void set(A&);
};
void set(A& obj) {
	obj.a = 10;
	obj.b = 100;
	obj.c = 1000;
}
int main() {
	A obj;
	set(obj);
	obj.print();
	return 0;
}