#include <iostream>
using namespace std;
string sumofnumbers(string num1, string num2){
	if (num1.length() > num2.length())
		swap(num1, num2);
	string sumas = "";
	int len1 = num1.length();
	int len2 = num2.length();
	int digs = len2 - len1;  
	int carry = 0;
	int suma;
	for (int i = len1 - 1; i >= 0; i--) {
		suma = ((num1[i] - '0') + (num2[i + digs] - '0') + carry);
		sumas.push_back(suma % 10 + '0');
		carry = suma / 10;
	}
	for (int i = digs - 1; i >= 0; i--) {
		suma = ((num2[i] - '0') + carry);
		sumas.push_back(suma % 10 + '0');
		carry = suma / 10;
	}
	if (carry)
		sumas.push_back(carry + '0');
	reverse(sumas.begin(), sumas.end());
	return sumas;
}
string modifyofnumbers(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
		return "0";
	string ymnoj(num1.size() + num2.size(), 0);
	for (int i = num1.size() - 1; i >= 0; i--) {
		for (int j = num2.size() - 1; j >= 0; j--) {
			int n = (num1[i] - '0') * (num2[j] - '0') + ymnoj[i + j + 1];
			ymnoj[i + j + 1] = n % 10;
			ymnoj[i + j] += n / 10;
		}
	}
	for (int i = 0; i < ymnoj.size(); i++) {
		ymnoj[i] += '0';
	}
	if (ymnoj[0] == '0') {
		return ymnoj.substr(1);
	}
	return ymnoj;
}
int main() {
	string num1;
	string num2;
	cin >> num1;
	cin >> num2;
	cout << sumofnumbers(num1, num2);
	cout << " " << endl;
	cout << modifyofnumbers(num1, num2);
}