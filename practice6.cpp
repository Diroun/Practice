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
	num.push_back(6); // push_back, добавляет число в конец вектора
	num.push_back(7);
	showvect(num);
	cout << " " << endl;
	//итератор - указатель для вектора, при помощи begin и end мы сами выбираем на что он будет указывать
	// erase, insert  требуют для себя использование итератора.
	vector<int>::iterator iter = num.begin(); // мы указываем на первый элемент вектора
	num.erase(iter);
	showvect(num); // удаляем первый элемент вектора
	cout << " " << endl;
	vector<int>::iterator iter1 = num.begin();
	num.insert(iter1+2, 8); // заменяем третий элемент вектора
	showvect(num);
	cout << " " << endl;
	num.emplace_back(9); // в отличии от push_back, emplace_back, добавляет элемент в вектор без копирования.
	showvect(num);
	num.resize(4); // меняем размер вектора, то есть можем его как уменьшить, так и увеличить.
	showvect(num);
	std::cout << "Capacity" << num.capacity() << std::endl; // capacity показывает, сколько элементов вектор может вместить без перевыделения памяти,
	num.reserve(12); // reserve занимается резервированием какого-то количества ячеек памяти для нашего вектора, но стоит учитывать, что значение reserve должно быть больше capacity
	cout << num.capacity() << endl; // после повтороного вызова capacity, заметим, что reserve добавил нам ячеек.
	num.shrink_to_fit(); // shrink_to_fit помогает нам освободить ячейки памяти вектора от неиспользуемых/пустых.
	cout << num.capacity() << endl; // проверим снова с помощью capacity, заметим, что оно уменьшилось
	num.clear(); // clear - полностью опустошил наш вектор, теперь там нет ничего
	showvect(num);
	num = { 10, 11, 12, 13,14 }; // присвоили новые значения нашему вектору
	vector <int> num1 = { 33, 41 }; // создали еще один вектор
	num = num1;
	showvect(num); // мы смогли присвоить значение 2-ого вектора 1-ому, теперь он поменял свои элементы и размер.
	num[1] = 201;
	num1[1] = num[1]; // заметим, что присвоить значение мы можем не только всему вектору, но и конкретному индексу
	showvect(num1);

	num = { 20, 40, 60, 80, 100 };
	cout << " " << endl;
	cout << sizeof(num)/8 << " byte" << endl;

}