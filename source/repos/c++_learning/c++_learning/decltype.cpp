#include<iostream>
using namespace std;
class foo {
private:
	int x;
public:
	explicit foo(int _x = 0) : x(_x) {

	}
	int get_x() {
		return this->x;
	}
	~foo() {

	}
};
template<class type1,class type2>
auto func = [](type1 x, type2 y) -> decltype(x + y) {
	return x + y;
};
int main() {
	foo f = foo(100);
	foo* f2(new foo(1000));
	decltype(f2) f3(new foo(10000));//f3's type is foo,same as f2 and f
	cout << "type of f3:" << typeid(f).name() << endl;
	cout << "sum is:" << func<int,float>(10, 10.5) << endl;
	cout << "type of func:" << typeid(func<int, float>(10, 10.5)).name() << endl;
	return 0;
}