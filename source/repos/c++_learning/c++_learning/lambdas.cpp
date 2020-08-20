#include<iostream>
#include<vector>
using namespace std;
void check(int x, void(*callback1)(void),void(*callback2)(void)) {
	if (x > 10)
	{
		callback1();
	}
	else
	{
		callback2();
	}
}
void vector_sort(vector<int>& v, bool(*callback)(int, int)) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (callback(v[j],v[i])) {
				int temp = v[j];
				v[j] = v[i];
				v[i] = temp;
			}
		}
	}
}
void vector_sort(vector<int> ::iterator begin, vector<int> ::iterator end, bool(*order)(int, int)) {
	//time complexity is O(n^2)
	for (auto it = begin; it != end; ++it) {
		for (auto it2 = it + 1; it2 != end; ++it2) {
			if (order((*it2), (*it))) {
				int temp = *it;
				*it = *it2;
				*it2 = temp;
			}
		}
	}
}
int main() {
	/*check(value, 
		[](void) {//using lambdas expresion
			cout << "is greater than 10";
		},
		[](void) {
			cout << "is less than 10";
		});*/
	//int a, b;
	//cout << "enter a:";
	//cin >> a;
	//cout << "enter b:";
	//cin >> b;
	//auto function = [=]/*pass by value*/(int a,int b) -> int  {
	//	int sum = a + b;
	//	return sum;
	//};
	//cout << "sum is:" << function(a, b) << endl;
	//vector sort
	auto ascending = [](int a, int b)->bool {
		return a < b;
	};
	auto descending = [](int a, int b)->bool {
		return a > b;
	};
	vector<int> v;
	//vector_sort(v,ascending);
	//vector_sort(v, descending);
	int n;
	cout << "enter n:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf_s("%d",&temp);
		v.push_back(temp);
	}
	vector_sort(v.begin(), v.end(), descending);
	printf_s("sorted order:\n");
	for (const auto& i : v) {
		printf_s("%d\t", i);
	}
	return 0;
}
//             ___          ___
//		      /  /|        /  /|
//		     /  / /       /  / /
//   	    /  / /       /  / /
//		   /  /_/_______/  / /           ___
//		  /  __________   / /  ___       )__)    ___      ___     _____________
//		 /  / _______ /  / /  /  /|     /  /|   /   \    /  /|   /  __________/|
//      /  / /       /  / /  /  / /    /  / /  /  /\ \  /  / /  /  /|_________|/
//     /  / /       /  / /  /  /_/____/  / /  /  /  \ \/  / /  /  / /
//    /__/ /       /  / /  /____________/ /  /__/ /\ \___/ /  /  / /     _______
//    |__|/        |__|/   |____________|/  |___|/  \|___|/  /  / /     /___   /|
//    <-------------------------------------------------->  /  / /      |__/  / /
//               ___     __________________                /  /_/_________/  / /
//              /  /|   /______    _______/|              /_________________/ /
//             /  / /   |_____/   / ______|/              |_________________|/
//            /  / /         /   / /
//           /  / /         /   / /<----------------------------------------------
//          /  / /         /   / /
//         /__/ /         /___/ /
//         |__|/          |___|/