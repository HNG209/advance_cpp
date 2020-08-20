#include<iostream>
using namespace std;
enum animals {
	COW,
	DOG,
	CAT,
	MOUSE
};
enum fruits {
	APPLE,
	ORANGE,
	MANGO,
	PINEAPPLE
};
//enum inside a class
class my_class {
public:
	enum state {
		ERROR,
		SUCCESS,
		FAIL
	};
	my_class() {

	}
	//do some examples
	void LOG(string message,my_class::state s) {
		if (s == my_class::ERROR) {
			cout << "[ERROR]:" << message << endl;
		}
		else if (s == my_class::FAIL) {
			cout << "[FAIL]:" << message << endl;
		}
		else {
			cout << "[SUCCESS]:" << message << endl;
		}
	}
	~my_class() {

	}
};
int main() {
	//animals A;
	//A = COW;
	//if (A == COW) {
	//	cout << "animal is a cow" << endl;
	//}
	my_class* A(new my_class);
	A->LOG("SYSTEM OVERLOADED!", my_class::FAIL);
	return 0;
}