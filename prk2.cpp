#include <iostream>

template <typename T>
void copyArray(T* mas1, T* mas2, int size) // создаю шаблонную функцию, с указателем T, который будет указывать на тип данных массива
{
    for (int i = 0; i < size; ++i) {
        mas2[i] = mas1[i];
    }
}

int main() {
    const int N = 10;
    int mas1[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int mas2[N];
    copyArray(mas1, mas2, N);
    std::cout << "Na4alniy massiv: ";
    for (int i = 0; i < N; ++i) {
        std::cout << mas1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Skopirovaniy Massiv: ";
    for (int i = 0; i < N; ++i) {
        std::cout << mas2[i] << " ";
    }
}