// Laba4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <ctime>                                         
#include <cmath>  
#include <time.h>
using namespace std;
const int n = 10;

void Sort_insert(int*array, int size) {
	int i, j, temp;
	int swap = 0, compare = 0;
	for (i = 1; i < size; i++)
	{
		/*выбираем элемент*/
		temp =array[i];
		for (j = i - 1; j >= 0; j--)
		{
			compare++;
			/*сравниваем*/
			if (array[j] < temp) {
				break;
			}
			else {
				/* меняем значения местами */
				array[j + 1] =array[j];
				array[j] = temp;
				swap++;
			}
		}
	}
	cout << "compare-" << compare << endl << "swap- " << swap << endl;
	return;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int array[n];
	//for (int i = 0; i < n; i++) {array[i] = i; };
	//for (int i = 0; i < n; i++) {array[i] = n - i; }
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 10;
		cout <<array[i] << endl;
	}
	int i, m;
	i = clock();
	Sort_insert(array, n);
	m = clock();
	float res = m - i;
	for (int i = 0; i < n; i++) { cout <<array[i] << " "; };
	cout << endl;
	cout << "тиков времени " << res << " или " << "time= " << res / CLOCKS_PER_SEC << "c." << endl;
	
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
