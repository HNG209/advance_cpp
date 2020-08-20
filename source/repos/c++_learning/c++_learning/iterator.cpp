#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	while (true) {
		int size;
		cout << "enter the size of your array:";
		cin >> size;
		vector<string> s;
		for (size_t i = 0; i < size; i++)
		{
			cout << "enter the " << i + 1 << " value :";
			for (string temp; cin >> temp;)
			{
				s.push_back(temp);
				if (cin.peek() == '\n') break;//nếu có kí tự xuống dòng
			}
		}
		cout << endl;
		cout << "string by string:" << endl;
        vector<string> ::iterator it;
		it = s.begin();
		while (it != s.end())
		{
			cout << *it << endl;
			++it;
		}
		cout << endl;
		it = s.begin();
		cout << "char by char :" << endl;
		while (it != s.end()) {
			for (size_t i = 0; (*it)[i] != '\0'; ++i)
			{
				cout << (*it)[i] << " ";
			}
			++it;
			cout << endl;
		}
	}
	return 0;
}