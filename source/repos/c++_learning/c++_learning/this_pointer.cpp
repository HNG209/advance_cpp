#include<iostream>
using namespace std;
class my_class {
private:
	int x = 100;//default value for x,x will be the 'first' block of memory
public:
	my_class(int _x) : x(_x) {//member initialize list
		//empty
	}
	my_class* return_this_pointer() {//or auto return_this_pointer()
		return this;//'this' is a pointer of my_class
	}
	auto/*int*/ return_dereference() {
		return *((int*)this);//dereferencing 'this' pointer,before it we have to cast it back to int pointer
	}
	auto call() {
		return this;
	}
	my_class() {

	}
	~my_class() {

	}
};
int main() {
	int value;
	cout << "pass a value to object:";
	cin >> value;
	//my_class* A(new my_class(value));//pass x
	my_class A(value);
	cout << "address of the object:0x" << A.return_this_pointer()/*->call()*/ << endl;
	cout << "dereferencing the address,we'll get the first block of memory that contained x=" << A.return_dereference() << endl;
	return 0;
}