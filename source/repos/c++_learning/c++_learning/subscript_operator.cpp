#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class safe_vector : public vector<T>{//inherit from vector class to use other functions
private:
	vector<T> vec;
public:
	safe_vector(int size) : vec(size) {
		for (int i = 0; i < size; i++) {
			vec[i] = 0;
		}
	}
	int &operator[](int index) {
		if (index >= vec.size()) {//use .size() from the vector class
			cout << "vector out of range!\n";
			return vec[0];
		}
		else {
			return vec[index];
		}
	}
	int size() {
		return vec.size();
	}
	void push_back(T value) {//không ghi đè đc nên viết lại
		vec.push_back(value);
	}
	~safe_vector() {

	}
};
int main() {
	int n;
	cout << "enter n:";
	cin >> n;
	safe_vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cout << "enter value " << i + 1 << ":";
		cin >> v[i];
	}
	cout << "your vector:\n";
	v.push_back(100);//dùng hàm trong safe_vector,ko dùng đc trong vector
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "enter index that you want to get from vector:";//nhập thử giá trị vượt quá số lượng phần tử
	int index;
	cin >> index;
	cout << "value at v[" << index << "]:" << v[index];
	return 0;
}