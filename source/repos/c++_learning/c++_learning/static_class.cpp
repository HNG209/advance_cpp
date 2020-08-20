#include<iostream>
using namespace std;
class myClass {
private:
public:
	static int count;
	myClass() {
		count++;
	}
	~myClass() {

	}
};
int myClass::count = 0;
class myClass2 {
private:
	static int count;
public:
	myClass2() {
		count++;
	}
	static int get() {
		return count;
	}
	~myClass2() {

	}
};
int myClass2::count = 0;
int main() {
	myClass* obj = new myClass[10];
	cout << myClass::count << endl;//accessing static member using class name
	myClass2* obj2 = new myClass2[100];
	cout << myClass2::get() << endl;
	return 0;
}