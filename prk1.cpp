#include <iostream>
#include <string>
using std::string;
using namespace std;

class Encrypt
{
	int m_key[30]{ 0 };
	bool m_rightkey;
	bool m_rightstr;
	string* m_str;
	int m_count;
private:
	bool check(int mas[], int count) // Proverka, 4to massiv sootvetstvuet Fibbonachi
	{
		if (mas[0] == 1 && mas[1] == 2)
		{
			for (int i = 2; i < count; ++i)
			{
				if (!(mas[i] == mas[i - 1] + mas[i - 2]))
					return false;
			}
		}
		else return false;
		return true;
	}
	void sorting(int mas[], int count) // Sortirovka po vozrastaniy
	{
		for (int i = 0; i < count - 1; ++i)
		{
			for (int j = 0; j < count - i - 1; ++j) 
			{
				if (mas[j] > mas[j + 1]) 
				{
					swap(mas[j], mas[j + 1]);
				}
			}
		}
	}
public:
	Encrypt() {}
	Encrypt(string* str, int& count) 
	{
		if (count <= 30)
		{
			m_str = str;
			m_count = count;
			m_rightstr = true;
		}
		else
		{
			cout << "Error: Neverno vvedena stroka!" << endl;
			m_rightstr = false;
		}
	}
	void Encode() // Algoritm zashivrovki
	{
		if (m_rightkey && m_rightstr)
		{
			int fib[30]{ 1,2 };
			for (int i = 2; i < m_count; ++i)
			{
				fib[i] = fib[i - 1] + fib[i - 2];
			}
			for (int i = 0; i < m_count; ++i)
			{
				for (int j = 0; j < m_count; ++j)
				{
					if (fib[j] == m_key[i] && i != j)
					{
						swap(fib[i], fib[j]);
						swap(m_str[i], m_str[j]);
					}
				}
			}
		}
		else
		{
			cout << "Vvedite klu4, i vashy frazu" << endl;
		}
	}
	void Decode() // Algoritm razshivrovki
	{
		if (m_rightkey && m_rightstr) {
			int tmpkey[30]{};
			for (int i = 0; i < m_count; ++i)
			{
				tmpkey[i] = m_key[i];
			}

			int fib[30]{ 1,2 };

			for (int i = 2; i < m_count; ++i)
			{
				fib[i] = fib[i - 1] + fib[i - 2];
			}

			for (int i = 0; i < m_count; ++i)
			{
				for (int j = 0; j < m_count; ++j)
				{
					if (fib[i] == tmpkey[j] && i != j)
					{
						swap(tmpkey[i], tmpkey[j]);
						swap(m_str[i], m_str[j]);
					}
				}
			}
		}
		else
		{
			cout << "Vvedite klu4, i vashy frazu" << endl;
		}
	}
	void Setupnewkey(const int mas[])  
	{
		int tmpkey[30]{};

		for (int i = 0; i < m_count; ++i)
		{
			tmpkey[i] = mas[i];
		}
		sorting(tmpkey, m_count);
		if (check(tmpkey, m_count))
		{
			m_rightkey = true;
			for (int i = 0; i < m_count; ++i)
			{
				m_key[i] = mas[i];
			}
		}
		else
		{
			cout << "Error:Vash klu4 neveren!" << endl;
			m_rightkey = false;
		}
	}
	void PrintKey()
	{
		if (m_rightkey)
		{
			for (int i = 0; i < m_count; ++i)
			{
				cout << m_key[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "Vvedite vash klu4:" << endl;
	}
	void SetStr(string* str, int& count)
	{
		if (count <= 30)
		{
			m_str = str;
			m_count = count;
			m_rightkey = true;
		}
		else
		{
			cout << "Error:Stroka vvedena neverno!" << endl;
			m_rightkey = false;
		}
	}
	void PrintStr()
	{
		if (m_rightstr)
		{
			for (int i = 0; i < m_count; ++i)
			{
				cout << m_str[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "Please, enter correct string" << endl;

	}
	~Encrypt() {};
};
int main()
{
	cout << "Vvedite stroky, kotoryy kodiruete (30 " << endl;
	string str;
	getline(cin, str);
	string masStr[30];
	int key[30];
	int count = 1;
	for (int i = 0; i < str.length() && count < 30; ++i)
	{
		if (str[i] != ' ')
		{
			masStr[count - 1] += str[i];
		}
		else
		{
			++count;
		}
	}
	cout << "Vvedite klu4, ispolzuite probel:" << endl;
	for (int i = 0; i < count; ++i)
	{
		cin >> key[i];
	}
	Encrypt qwe(masStr, count);
	qwe.Setupnewkey(key);
	qwe.Encode();
	qwe.PrintStr();
	qwe.Decode();
	qwe.PrintStr();
}