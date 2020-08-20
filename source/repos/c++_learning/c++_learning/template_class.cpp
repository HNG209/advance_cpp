#include<iostream>
#include<vector>
using namespace std;
template<class T> class my_class {
public:
	my_class();
	void set_arr();
	void show_arr();
	~my_class();
private:
	T *arr;
	int size;
};
template<class T> my_class<T>::my_class() {

}
template<class T> void my_class<T>::set_arr() {
	cout << "enter your size:";
	cin >> this->size;
	this->arr = (T*)malloc(size * sizeof(T*));
	for (size_t i = 0; i < size; i++)
	{
		cout << "enter the " << i + 1 << " value:";
		cin >> *(arr + i);
	}
}
template<class T> void my_class<T>::show_arr() {
	for (size_t i = 0; i < this->size; i++)
	{
		cout << "value " << i+1 << ":" << this->arr[i] << endl;
	}
}
template<class T> my_class<T>::~my_class() {

}
template<typename T> class math {
public:
	T Sum(vector<T> arr) {
		vector<int>:: iterator it;
		it = arr.begin();
		while (it!= arr.end())
		{
			this->sum += (*it);
			++it;
		}
		return sum;
	}
	void enter(vector<T>* arr,int value) {
		for (int i = 0; i < value; i++) {
			int temp;
			cout << "enter the " << i + 1 << " value:";
			cin >> temp;
			(*arr).push_back(temp);
		}
	
	}
private:
	T sum = 0;
};
int main() {
	vector<int> s_arr;
	math<int>* s= new math<int>;
	int n;
	cout << "how many integers do you want to have:";
	cin >> n;
	s->enter(&s_arr,n);
	cout << "sum is " << s->Sum(s_arr) << endl;
	delete s;
	return 0;
}