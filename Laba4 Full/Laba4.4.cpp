// Laba4.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <ctime>                                         
#include <cmath>  
#include <time.h>
using namespace std;
const int n = 10;
int count = 0, countP = 0;

void Sort_Quick(int* array, int first, int last) {
	int i = first, j = last, x = array[(first + last) / 2];/*выбрали элемент, относительно которого будем сортировать*/
	do {
		while (array[i] < x) {
			i++;
			::count++;
		}
		while (array[j] > x) {
			j--;
			::count++;
		}
		::count++;
		if (i <= j) {
			::count++;
			if (array[i] > array[j]) {
				/* меняем значения местами */
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				::countP++;
			}
			i++;
			j--;
		}
	} while (i <= j);
	::count += 2;
	if (i < last) {
		Sort_Quick(array, i, last);
	}
	if (first < j) {
		Sort_Quick(array, first, j);
	}
	cout << endl;
	
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int array[n];
	//for (int i = 0; i < n; i++) { array[i] = i; };
	//for (int i = 0; i < n; i++) { array[i] = n - i; }
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 10;
		cout << array[i] << endl;
	}
	int i, m;
	i = clock();
	Sort_Quick(array, 0,n-1);
	m = clock();
	float res = m - i;
	for (int i = 0; i < n; i++) { cout << array[i] << " "; };
	cout << endl;
	
	cout << "тиков времени " << res << " или " << "time= " << res / CLOCKS_PER_SEC << "c." << endl;
	cout << "compare-" << ::count << endl << "swap- " << ::countP << endl;
	system("pause");
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
