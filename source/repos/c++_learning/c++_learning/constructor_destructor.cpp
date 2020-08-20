#include<iostream>
using namespace std;
class A {
public:
	A(void) {//constructor
		cout << "class initialized!" << endl;
	}
	void do_st() {
		cout << "hello compiler" << endl;
	}
	~A(void) {//destructor
		cout << "destroyed class!" << endl;
	}
};
int main() {
	A* a = new A;
	a->do_st();
	//delete a;
	cin.get();
}