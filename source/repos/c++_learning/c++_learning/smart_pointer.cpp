#include<iostream>
#include<memory>
#include<vector>
using namespace std;
class myclass {
private:
	int x;
public:
	myclass(int value = 0) : x(value) {
		cout << "constructor called with value:" << this->x << endl;
	}
	~myclass() {
		cout << "destructor called" << endl;
	}
};
//don't need to write constructor copying function if there was using shared pointer
class foo {
private:
	std::shared_ptr<int> x;
public:
	foo(int* _x) : x(_x) {
		printf_s("constructor called with passing parameter:%d\n", *x);
	}
	int get_count() {
		return x.use_count();
	}
	void change(int x) {
		*this->x = x;
	}
	int get_x() {
		return *x;
	}
	~foo() {
		printf_s("destructor called\n");
	}
};
int main() {
	const int size = 20;
	//creating array with smart pointer
	std::unique_ptr<int[]> d_arr = std::make_unique<int[]>(size);
	//std::unique_ptr<int[]> d_arr(new int[100]);//or this
	for (int i = 0; i < size; i++) {
		d_arr[i] = i;//looping through elements
	}
	for (int i = 0; i < size; i++) {
		cout << d_arr[i] << " ";//looping through elements
	}
	std::unique_ptr<int[]> d_arr2(std::move(d_arr));//move the constructor(move semantic) of d_arr to d_arr2,d_arr is now a null pointer
	if (d_arr == nullptr) {//after moving constructor of d_arr,let's see if it was a nullptr
		cout << "\nd_arr is a null pointer\n";
	}
	else {
		cout << "\nd_arr is not a null pointer\n";
	}
	cout << "d_arr2 is:\n";
	for (int i = 0; i < size; i++) {
		cout << d_arr2[i] << ' ';//d_arr2 holds the constructor of d_arr
	}
	//----------------------------------------------------------------------------
	int* p = new int(100);
	std::unique_ptr<int> ptr(p);//initialize a heap-based variable
	std::unique_ptr<int> ptr2(std::move(ptr));//same topology
	if (ptr == nullptr) {
		cout << "\nis null pointer\n";
	}
	else {
		cout << "\nis not null pointer\n";
	}
	cout << "ptr2 is:" << *ptr2 << endl;
	//-------------------------------------------------------------------------
	//shared pointer:
	{
	foo x(new int(100));
	foo y(x);
	foo z(y);
	cout << "reference count:" << x.get_count() << endl;
	cout << "before,x was:" << x.get_x() << endl;
	y.change(2909);
	cin.get();//press enter to see next
	cout << "now it is:" << x.get_x() << endl;
	cin.get();//press enter to exit scope and see destructor's call
	}
	//-------------------------------------------------------------------------
	{
		std::shared_ptr<myclass> A = std::make_shared<myclass>(10);//1(new value)
		std::shared_ptr<myclass> B(A);//2
		std::shared_ptr<myclass> C(B);//3
		std::shared_ptr<myclass> D(C);//4
		decltype(A) E(A);
		cout << "reference count:" << E.use_count() << endl;
		std::cin.get();//press enter to exit scope and see destructor's call
	}//out of scope
	std::cin.get();
	foo* s(new foo(new int(100)));
	cout << "bonus:" << s->get_x();
	cin.get();//it won't call destructor
	//this is freaking me out
	std::shared_ptr<vector<int>> vec = std::make_shared<vector<int>>();
	vec->push_back(10);
	cout << "vec0 is:" << vec->operator[](0) << endl;
	std::shared_ptr<vector<vector<int>>> vec2d = std::make_shared <vector<vector<int>>>();
	//ddjt me choangs vaix loonf
	vector<int> temp{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> temp2{ 10,9,8,7,6,5,4,3,2,1 };
	vec2d->push_back(temp);
	vec2d->push_back(temp2);
	cout << "vec2d[0][0] is:" << vec2d->operator[](0).at(0) << endl;
	for (int i = 0; i < vec2d->size(); i++) {
		for (const auto& it : vec2d->operator[](i)) {
			cout << it << '\t';
		}
		cout << '\n';
	}
	return 0;
}