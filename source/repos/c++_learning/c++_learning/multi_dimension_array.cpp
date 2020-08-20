#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<vector<int>> vec2d;
	int row, colum;
	cout << "how many rows do you want to have?:";
	cin >> row;
	cout << "how many colums do you want to have?:";
	cin >> colum;
	for (int i = 0; i < row; i++) {
		vector<int> temp;
		cout << "enter the " << i + 1 << " row:" << endl;
		for (int j = 0; j < colum; j++) {
			cout << "enter the " << j + 1 << "element:";
			int tempo;
			cin >> tempo;
			temp.push_back(tempo);
		}
		vec2d.push_back(temp);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++) {
			cout << vec2d[i][j];
		}
		cout << endl;
	}
	vector<vector<vector<int>>> vec3d;
	int x, y, z;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	cout << "z=";
	cin >> z;
	vector<int> temp_z;
	vector<vector<int>> temp_y;
	for (int a = 0; a < x; a++) {
		cout << "block " << a + 1 << endl;
		for (int b = 0; b < y; b++) {
			cout << "rows element:" << endl;
			for (int c = 0; c < z; c++) {
				int tempo_z;
				cout << "enter the " << c + 1 << " element of colums:";
				cin >> tempo_z;
				temp_z.push_back(tempo_z);
			}
			temp_y.push_back(temp_z);
		}
		vec3d.push_back(temp_y);
	}
	for (int a = 0; a < x; a++) {
		for (int b = 0; b < y; b++) {
			for (int c = 0; c < z; c++) {
				cout << vec3d[a][b][c];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}