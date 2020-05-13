// Laba4.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <ctime>                                         
#include <cmath>  
#include <time.h>
using namespace std;
const int n = 10;

int count=0 ;
int countT=0;

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int left = 2 * i + 1; // левый = 2*i + 1
	int right = 2 * i + 2; // правый = 2*i + 2
	::count++;
 // Если левый дочерний элемент больше корня
	if (left < n && arr[left] > arr[largest])
		largest = left;
	
	::count++;
	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (right < n && arr[right] > arr[largest])
		largest = right;
	  
	
	// Если самый большой элемент не корень
	if (largest != i)
	{
		::count++;
		swap(arr[i], arr[largest]);
		::countT++;
		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
	


}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{

	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--) {
		::count ++;
		heapify(arr, n, i);
	}
	

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);
		::countT++;

		// вызываем процедуру heapify на уменьшенной куче
		::count ++;
		heapify(arr, i, 0);
	}
	
}

/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Управляющая программа
int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[n];
	srand(time(0));
	int n = sizeof(arr) / sizeof(arr[0]);

	
	//for (int i = 0; i < n; i++) { arr[i] = i; };
	//for (int i = 0; i < n; i++) { arr[i] = n - i; }
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << endl;
	}
	cout << endl;
	int i, m;
	i = clock();
	heapSort(arr, n);
	cout << "Sorted array is \n";
	printArray(arr, n);
	m = clock();
	float res = m - i;
	
	cout << "compare-" << ::count << endl << "swap- " << ::countT << endl;
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
