#include<iostream>
using namespace std;
class Animals {
public:
	Animals(void) {

	}
	virtual void move() {
		cout << "is moving" << endl;
	}
	~Animals(void) {

	}
};
class bird : public Animals {
public:
	bird();
	void move() override {
		cout << "is flying" << endl;
	}
	~bird();
};
bird::bird() {
	cout << "bird initialized!" << endl;
}
bird::~bird() {
	cout << "bird deallocated!" << endl;
}
class fish : public Animals {
public:
	fish();
	void move() override {
		cout << "is swimming" << endl;
	}
	~fish();
};
fish::fish() {
	cout << "fish initialized!" << endl;
}
fish::~fish() {
	cout << "fish deallocated!" << endl;
}
int main() {
	Animals* A = new bird;
	A->move();
	A = new fish;
	A->move();
	delete A;
	return 0;
}