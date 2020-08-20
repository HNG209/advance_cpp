#include<iostream>
#include<array>
using namespace std;
struct s {
	int a, b, c;
};
//typedef s mtype;
//pass std array as a function parameters
template<int size>
auto func = [](std::array<int, size> st_arr) -> void {
	auto it = st_arr.begin();
	while (it != st_arr.end()) {
		cout << *it << '\t';
		++it;
	}
};
int main() {
	std::array<int, 10> arr{ 0,1,2,3,4,5,6,7,8,9 };
	func<arr.size()>(arr);
	std::array<s,3> arr2 
	{
		{
		{1,1,1},
		{2,2,2},
		{3,3,3}
		}
	};
	cout << arr2[0].a << " " << arr2[0].b  << " " << arr2[0].c << endl;
	cout << arr2[1].a << " " << arr2[1].b << " " << arr2[1].c << endl;
	cout << arr2[2].a << " " << arr2[2].b << " " << arr2[2].c << endl;
	std::array<s, 5> arr3;
	cin >> arr3[0].a >> arr3[0].b >> arr3[0].c;
	cin >> arr3[1].a >> arr3[1].b >> arr3[1].c;
	cout << arr3[0].a << " " << arr3[0].b << " " << arr3[0].c << endl;
	cout << arr3[1].a << " " << arr3[1].b << " " << arr3[1].c << endl;
	return 0;
}