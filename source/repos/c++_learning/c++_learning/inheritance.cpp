#include<iostream>
#include<string>
using namespace std;
class person
{
public:
	person(void);
	void set_name(void);
	void set_id(void);
	void info(void);
	~person(void);

protected:
	string name;
	string id;
};

person::person(void)
{
}
void person::set_name(void) {
	cout << "enter name:";
	for (string temp; cin >> temp;) {
		this->name = temp;
		if (cin.peek() == '\n') break;
	}
}
void person::info(void) {
	cout << "-------------your info--------------" << endl;
	cout << "name:" << this->name << endl;
	cout << "ID:" << this->id << endl;
}
void person::set_id(void) {
	cout << "enter id:";
	for (string temp; cin >> temp;) {
		this->id = temp;
		if (cin.peek() == '\n') break;
	}
}
person::~person(void)
{
}
class student : public person//inheritate
{
public:
	student(void);
	void std_name_set(void);
	void std_id_set(void);
	void show_info(void);
	~student(void);

private:

};

student::student(void)
{
}
void student::std_name_set(void) {
	set_name();
}
void student::std_id_set(void) {
	set_id();
}
void student::show_info(void) {
	//info();
	cout << "---------INFO---------" << endl;
	cout << "name:" << this->name << endl;
	cout << "ID:" << this->id << endl;
}
student::~student(void)
{
}
int main() {
	student s;
	s.set_name();
	s.set_id();
	s.show_info();
	return 0;
}