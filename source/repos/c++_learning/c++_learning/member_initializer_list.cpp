#include<iostream>
#include<vector>
using namespace std;
class A {
private:
	int a;
public:
	A() : a(0) {
		//
	}
	A(int n) : a(n) {
		//
	}
	void printA() {
		cout << a << endl;
	}
	~A(void) {

	}
};
class B {
private:
	A obj;
	int b;
public:
	B(int n) : b(n), obj(n) {

	}
	void print() {
		this->obj.printA();
		cout << b << endl;
	}
	~B(void) {

	}
};
int main() {
	B object(10);
	object.print();
	return 0;
}