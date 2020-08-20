#include<iostream>
#include<vector>
using namespace std;
class my_class {
public:
	my_class() {
		//empty constructor
	}
	auto call() {
		cout << "hello world\n";
		return this;//return the object(this)
	}
	auto call1() {
		cout << "hello CPP\n";
		return this;//return the object(this)
	}
	auto call2() {
		cout << "hello this is Hung\n";
		return this;//return the object(this)
	}
	auto call3() {
		cout << "hello this is Hung again\n";
		return this;//return the object(this)
	}
	int calculate() {//function that return another value cannot be chainned between
		return 10;
	}
	~my_class() {
		//empty destructor
	}
};
int main() {
	//clone from javascript
	my_class A;
	cout << "they all have the same address:" << endl;
	cout << A.call() << endl;
	cout << A.call1() << endl;
	cout << A.call2() << endl;
	cout << A.call3() << endl;
	//instead of doing this
	//A.call();
	//A.call1();
	//A.call2();
	//A.call3();
	//cout << calculate() << endl;
	//use chaining function(only use for function that has non-returned value)
	cout << A.call()->call1()->call2()->call3()->calculate() << endl;//chaining function
	cout << "memory address of this pointer:" << A.call()->call()->call()->call()->call();
	return 0;
}