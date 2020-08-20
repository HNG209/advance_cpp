#include<iostream>
using namespace std;
class add {
public:
	add(int value) : x{ new int(value) } {
	}
	add() {

	}
	void operator=(const add& that) {
		this->x = new int(*that.x);
	}
	void print() {
		cout << *(this->x) << endl;
	}
	~add() {
		delete this->x;
	}
	friend ostream& operator<<(ostream& out,const add& that) {
		out << *(that.x);
		return out;
	}
private:
	int* x;
};
class myclass {
private:
	std::shared_ptr<int> x;//all the object will have their own reference key
public:
	myclass(int value) : x {new int(value)}{

	}
	myclass() {
		//do nothing,empty constructor
	}
	void print() {
		cout << *(this->x) << endl;
	}
	friend ostream& operator<<(ostream& out, const myclass& obj) {
		out << *(obj.x);
		return out;
	}
	~myclass() {

	}
};
int main() {
	myclass a = 10;
	myclass b = 1000;
	a = b;
	myclass c;
	c = b;
	cout << "a=" << a << ",b=" << b << ",c=" << c;
	return 0;
}