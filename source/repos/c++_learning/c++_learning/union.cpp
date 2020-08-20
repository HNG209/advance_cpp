#include<iostream>
using namespace std;
union un {
	struct {
		int x, y, z;
	};
	//R,G,B will use the same memory as x,y,z
	//total of 3 x 4 bytes of memory(12 bytes)
	struct {
		int R, G, B;
	};
	//add methods
	int length() {
		return sizeof(un);
	}
	void print_union() {
		cout << "length of union:" << this->length() << "B" << endl;
		cout << "u.R:" << this->R << endl;
		cout << "u.G:" << this->G << endl;
		cout << "u.B:" << this->B << endl;
		cout << "u.x:" << this->x << endl;
		cout << "u.y:" << this->y << endl;
		cout << "u.z:" << this->z << endl;
	}
};
//vs struct
struct str {
	struct {
		int x, y, z;
	};
	//total should be 6 x 4 bytes of memory(24 bytes)
	struct {
		int R, G, B;
	};
	//add methods
	int length() {
		return sizeof(str);
	}
	void print_struct() {
		cout << "struct length:" << this->length() << "B" << endl;
		cout << "s.R:" << this->R << endl;
		cout << "s.G:" << this->G << endl;
		cout << "s.B:" << this->B << endl;
		cout << "s.x:" << this->x << endl;
		cout << "s.y:" << this->y << endl;
		cout << "s.z:" << this->z << endl;
	}
};
void print_union(union un u) {
	cout << "length of union:" << sizeof(u) << "B" << endl;
	cout << "u.R:" << u.R << endl;
	cout << "u.G:" << u.G << endl;
	cout << "u.B:" << u.B << endl;
	cout << "u.x:" << u.x << endl;
	cout << "u.y:" << u.y << endl;
	cout << "u.z:" << u.z << endl;
}
void print_struct(struct str s) {
	cout << "struct length:" << sizeof(s) << endl;
	cout << "s.R:" << s.R << endl;
	cout << "s.G:" << s.G << endl;
	cout << "s.B:" << s.B << endl;
	cout << "s.x:" << s.x << endl;
	cout << "s.y:" << s.y << endl;
	cout << "s.z:" << s.z << endl;
}
int main() {
	un u;
	str s{ 1,2,3,4,5,6 };
	u.x = 100;
	u.y = 255;
	u.z = 10;
	u.print_union();
	s.print_struct();
	return 0;
}