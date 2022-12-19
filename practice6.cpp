#include <iostream>
#include <vector>
using namespace std;
void showvect(vector <int>vec) {
	cout << "vector" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << " " << endl;
}
int main() {
	vector<int> num = {1, 2, 3, 4, 5};
	showvect(num);
	num.push_back(6); // push_back, ��������� ����� � ����� �������
	num.push_back(7);
	showvect(num);
	cout << " " << endl;
	//�������� - ��������� ��� �������, ��� ������ begin � end �� ���� �������� �� ��� �� ����� ���������
	// erase, insert  ������� ��� ���� ������������� ���������.
	vector<int>::iterator iter = num.begin(); // �� ��������� �� ������ ������� �������
	num.erase(iter);
	showvect(num); // ������� ������ ������� �������
	cout << " " << endl;
	vector<int>::iterator iter1 = num.begin();
	num.insert(iter1+2, 8); // �������� ������ ������� �������
	showvect(num);
	cout << " " << endl;
	num.emplace_back(9); // � ������� �� push_back, emplace_back, ��������� ������� � ������ ��� �����������.
	showvect(num);
	num.resize(4); // ������ ������ �������, �� ���� ����� ��� ��� ���������, ��� � ���������.
	showvect(num);
	std::cout << "Capacity" << num.capacity() << std::endl; // capacity ����������, ������� ��������� ������ ����� �������� ��� ������������� ������,
	num.reserve(12); // reserve ���������� ��������������� ������-�� ���������� ����� ������ ��� ������ �������, �� ����� ���������, ��� �������� reserve ������ ���� ������ capacity
	cout << num.capacity() << endl; // ����� ����������� ������ capacity, �������, ��� reserve ������� ��� �����.
	num.shrink_to_fit(); // shrink_to_fit �������� ��� ���������� ������ ������ ������� �� ��������������/������.
	cout << num.capacity() << endl; // �������� ����� � ������� capacity, �������, ��� ��� �����������
	num.clear(); // clear - ��������� ��������� ��� ������, ������ ��� ��� ������
	showvect(num);
	num = { 10, 11, 12, 13,14 }; // ��������� ����� �������� ������ �������
	vector <int> num1 = { 33, 41 }; // ������� ��� ���� ������
	num = num1;
	showvect(num); // �� ������ ��������� �������� 2-��� ������� 1-���, ������ �� ������� ���� �������� � ������.
	num[1] = 201;
	num1[1] = num[1]; // �������, ��� ��������� �������� �� ����� �� ������ ����� �������, �� � ����������� �������
	showvect(num1);

	num = { 20, 40, 60, 80, 100 };
	cout << " " << endl;
	cout << sizeof(num)/8 << " byte" << endl;

}