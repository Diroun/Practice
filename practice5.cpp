#include <iostream>
class Dynamomassive {
private:
	int m_counts = 1;
	int* m_massive = new int[m_counts];

public:
	Dynamomassive(int mas1)
	{
		m_counts = 1;
		m_massive[0] = mas1;
		std::cout << mas1 << std::endl;
	}


	void newelemen(int elem)
	{
		int* massive = new int[m_counts + 1];
		for (int i = 0; i < m_counts; i++) {
			massive[i] = m_massive[i];
		}
		massive[m_counts] = elem;
		delete[] m_massive;
		m_massive = massive;
		m_counts++;
	}
	int counts() {
		return m_counts;
	}

	int elem(int number) {
		return m_massive[number];

	}
	void allelem() {
		for (int i = 0; i < m_counts; i++) {
			std::cout << m_massive[i] << " ";
		}
	}
	void installelem(int elem, int number) {
		m_massive[number] = elem;
	}
	void deleteelem(int number) {
		for (int i = number; i < m_counts - 1; i++) {
			m_massive[i] = m_massive[i + 1];
		}
		m_counts--;
	}
	void inelem(int number, int elem) {
		int* massive = new int[m_counts + 2];
		for (int i = 0; i < number; i++) {
			massive[i] = m_massive[i];
		}
		massive[number] = elem;
		for (int i = number + 1; i < m_counts + 1; i++)
		{
			massive[i] = m_massive[i - 1];
		}
		m_counts++;
		delete[] m_massive;
		m_massive = massive;
	}
};
	int main() {
		Dynamomassive boom1(1);
		boom1.newelemen(2);
		boom1.newelemen(3); // 1.добавили элемент
		boom1.allelem(); // выдаем весь массив
		std::cout << std::endl;
		std::cout <<"teky4ee kol-vo elementov "<<boom1.counts() << std::endl; // 2. текущее кол-во элементов
		std::cout << "perviy element " << boom1.elem(0) << std::endl; // 3. вызвали элемент по индексу
		std::cout << std::endl;
		boom1.allelem();
		std::cout << std::endl;
		std::cout << "Zamena elementa" << std::endl;
		boom1.installelem(6, 1); // 4. мы изменили элемент по индексу
		boom1.allelem();
		std::cout << std::endl;
		std::cout <<"Ydalenie pervogo elementa"<< std::endl;
		boom1.deleteelem(0); //5. удалили элемент по индексу
		boom1.allelem();
		std::cout << std::endl;
		std::cout << "Vstavim element" << std::endl; //6. вставляем в массив элемент по индексу
		boom1.inelem(1,15);
		boom1.allelem();


	}