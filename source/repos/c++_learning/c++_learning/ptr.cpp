#include<iostream>
using namespace std;
int main() {
	//----địa chỉ của các phần tử trong mảng 1 chiều cấp phát động/tĩnh---
	int* arr;
	//toán tử địa chỉ &
	arr = new int[10];//tạo mảng động
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	for (size_t i = 0; i < 10; i++)
	{
		//sử dụng toán tử địa chỉ để lấy từng địa chỉ của từng phần tử trong mảng
		cout << "address at arr[" <<  i  << "]= 0x" << &arr[i] << endl;
	}
	//---------địa chỉ của con trỏ và địa chỉ của biến đc trỏ tới--------
	int a = 100;//biến thông thường
	int* ptr;//con trỏ ptr
	ptr = &a;//tham chiếu tới địa chỉ của a &
	cout << "address of pointer,should be different from address of a:0x";
	cout << ptr << endl;//print ra địa chỉ của biến đc trỏ tới(a)
	cout << "address of 'a' that pointer pointed to:0x";
	cout << &ptr << endl;//do con trỏ cũng có ô nhơ riêng của nó nên nó cũng có địa chỉ như biến thông thường
	cout << "dereferencing to get the value of a,we will have:";
	cout << *ptr << endl;//giải tham chiếu(dereference) địa chỉ của mà con trỏ đang trỏ tới,ta lấy đc giá trị tại địa chỉ đó
	*ptr = 2909;//con trỏ có toàn quyền sử dụng ô nhớ của biến khác,thay đổi giá trị tại ô nhớ đó
	cout << "ptr has changed the value of 'a':";
	cout << a << endl;//a đã bị thay đổi
	//---------------con trỏ trỏ tới con trỏ--------------
	cout << "pointer to pointer:" << endl;
	int** p;//con trỏ đang trỏ tới con trỏ khác
	int* x;//con trỏ đang trỏ tới biến khác
	int b = 1000;//biến thông thường
	x = &b;//như phần trên
	p = &x;//con trỏ bây giờ chỉ có thể trỏ tới con trỏ khác,trỏ về biến sẽ bị lỗi
	//p = &b lỗi
	//con trỏ p giờ đang lưu địa chỉ của con trỏ x
	//nếu print ra ta đc địa chỉ của con trỏ x
	cout << "memory address of x pointer that p pointer pointed to:0x";
	cout << p << endl;//địa chỉ của con trỏ x(.)
	//cout << &x << endl;//như trên
	//bây giờ nếu muốn từ con trỏ p mà lấy đc giá trị của b thì
	//ta giải tham chiếu từ con trỏ x,khi đó x chứa giá trị của b
	//ta lại dùng con trỏ p giải tham chiếu tới địa chỉ của x
	//lần nữa,ta có giá trị của b
	//(ko cần ghi)*p = &(*x);//trỏ tới địa chỉ của x chứ chưa giải tham chiếu
	//nếu in ra dòng trên,tức là chỉ print ra *p,ta lấy đc địa chỉ của con trỏ p
	cout << "print out the memory address of p pointer:0x";
	cout << *p << endl;//địa chỉ của con trỏ p(.)
	cout << "dereference twice to get the value of b,we'll have:";
	cout << *(*p)/* hoặc như thế này:**p */ << endl;//giải tham chiếu,nói cách khác là giải tham chiếu '2 lần'
	return 0;
}