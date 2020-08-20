#include<iostream>
#include<vector>
using namespace std;
class my_class {
private:
	std::vector<string> students;
	std::vector<int> avr_marks;
	int std_num;
public:
	my_class(int);
	void set_name(void);
	void set_mark(void);
	void show_full(void);
	~my_class();
};
my_class::my_class(int std_num) {
	this->std_num = std_num;
}
void my_class::set_name(void) {
	for (size_t i = 0; i < this->std_num; i++)
	{
		cout << "student " << i + 1 << ":";
		for (string temp; cin >> temp;) {
			this->students.push_back(temp);
			if (cin.peek() == '\n') break;
		}
	}
}
void my_class::set_mark(void) {
	for (size_t i = 0; i < this->std_num; i++)
	{
		cout << this->students.at(i) << "'s avarage mark:";
			int temp;
		    cin >> temp;
			this->avr_marks.push_back(temp);
	}
}
void my_class::show_full(void) {
	cout << "-------------CLASS'S INFO-----------" << endl;
	for (size_t i = 0; i < this->std_num; i++)
	{
		cout << this->students.at(i) << " : " << this->avr_marks.at(i) << endl;
	}
}
my_class::~my_class() {

}
int main() {
	my_class _10A0(4);
	_10A0.set_name();
	_10A0.set_mark();
	_10A0.show_full();
}