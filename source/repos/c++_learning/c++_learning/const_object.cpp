#include<iostream>
#include<string>
using namespace std;
class obj {
public:
	obj() {

	}
	int getID() const {
		return ID;
	}
	string getVendor() const {
		return vendor;
	}
	string get_date() const {
		return date;
	}
	~obj() {

	}
private:
	int ID = 218931897;
	string vendor = "hungtran2k4";
	string date = "29-09-2004";
};
int main() {
	const obj readOnly;
	cout << readOnly.getID() << endl;
	cout << readOnly.getVendor() << endl;
	cout << readOnly.get_date() << endl;
	return 0;
}