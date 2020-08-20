#include<iostream>
using namespace std;
class Vector {
private:
	int x, y;
public:
	Vector();
	Vector(int, int);
	int get_x() {
		return this->x;
	}
	int get_y() {
		return this->y;
	}
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator*(const Vector&);
	Vector operator/(const Vector&);
	Vector operator-(int);
	Vector operator*(int);
	Vector operator+(int);
	Vector operator/(int);
	Vector operator+=(int);
	Vector operator-=(int);
	Vector operator++();
	Vector operator++(int);
	Vector operator--();
	bool operator==(const Vector&);
	bool operator>=(const Vector&);
	bool operator<=(const Vector&);
	bool operator<(const Vector&);
	bool operator>(const Vector&);
	friend ostream& operator<<(ostream& out, const Vector& vec) {//output overloaded
		out << "(" << vec.x << "," << vec.y << ")";
		return out;
	}
	friend istream& operator>>(istream& in, Vector& vec) {//input overloaded
		in >> vec.x >> vec.y;
		return in;
	}
	~Vector();
};
Vector::Vector() {
	this->x = 0;
	this->y = 0;
}
Vector::Vector(int x, int y) {
	this->x = x;
	this->y = y;
}
Vector Vector::operator+(const Vector& vec) {
	Vector temp;
	temp.x = this->x + vec.x;
	temp.y = this->y + vec.y;
	return temp;
}
Vector Vector::operator-(const Vector& vec) {
	Vector temp;
	temp.x = this->x - vec.x;
	temp.y = this->y - vec.y;
	return temp;
}
Vector Vector::operator*(const Vector& vec) {
	Vector temp;
	temp.x = this->x * vec.x;
	temp.y = this->y * vec.y;
	return temp;
}
Vector Vector::operator++(int) {
	Vector vec(x, y);
	this->x++;
	this->y++;
	return vec;
}
bool Vector::operator==(const Vector& vec) {
	if (this->x == vec.x && this->y == vec.y)
	{
		return true;
	}
	else {
		return false;
	}
}
Vector Vector::operator++() {
	this->x++;
	this->y++;
	return Vector(x,y);
}
Vector Vector::operator-=(int x) {
	Vector temp;
	temp.x -= x;
	temp.y -= x;
	return temp;
}
Vector Vector::operator+=(int x){
	Vector temp;
	temp.x += x;
	temp.y += x;
	return temp; 
}
bool Vector::operator<=(const Vector& vec) {
	if (this->x <= vec.x && this->y <= vec.y) {
		return true;
	}
	else {
		return false;
	}
}
Vector Vector::operator--() {
	this->x--;
	this->y--;
	return Vector(x, y);
}
Vector Vector::operator/(int x) {
	Vector temp;
	temp.x = this->x / x;
	temp.y = this->y / x;
	return temp;
}
Vector Vector::operator*(int k) {
	Vector temp;
	temp.x = this->x * k;
	temp.y = this->y * k;
	return temp;
}
bool Vector::operator>=(const Vector& vec) {
	if (this->x >= vec.x && this->y >= vec.y) {
		return true;
	}
	else {
		return false;
	}
}
bool Vector::operator<(const Vector& vec) {
	if (this->x < vec.x && this->y <vec.y)
	{
		return true;
	}
	else {
		return false;
	}
}
bool Vector::operator>(const Vector& vec) {
	if (this->x > vec.x && this->y > vec.y) {
		return true;
	}
	else {
		return false;
	}
}
Vector Vector::operator+(int x) {
	Vector temp;
	temp.x = this->x + x;
	temp.y = this->y + x;
	return temp;
}
Vector Vector::operator/(const Vector& vec) {
	Vector temp;
	temp.x = this->x / vec.x;
	temp.y = this->y / vec.y;
	return temp;
}
Vector Vector::operator-(int k) {
	Vector temp;
	temp.x = this->x - k;
	temp.y = this->y - k;
	return temp;
}
Vector::~Vector() {

}
int main() {
	Vector A(2, 2);
	Vector B(2, 2);
	Vector I;
	if (A == B) {
		cout << "2 vectors is the same" << endl;
	}
	I = (A + B) / 2;
	cout << "middle point:" << "I" << I << endl;
    A++;
	cout << A << endl;//output overloaded
	A++;
	cout << A << endl;
	cout << "enter a vector:" << endl;
	Vector vec;
	cin >> vec;
	cout << "vec" << vec;
	return 0;
}