// Lab6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;

struct stek {
	int x;
	stek *Next, *Head;
};

void add(int x, stek *&Mystek) {
	stek *temp = new stek;
	temp->x = x;
	temp->Next = Mystek->Head;
	Mystek->Head = temp;
}

void show(stek *Mystek) {
	stek *temp = Mystek->Head;
	while (temp != NULL) {
		cout << temp->x << " ";
		temp = temp->Next;
	}
	cout << endl;
}

void dele(stek *Mystek) {
	stek *temp = Mystek->Head->Next;
	delete Mystek->Head;
	Mystek->Head = temp;
}

struct dek {
	int x;
	dek* Next;
	dek* Head;
};
struct DEK {
	dek* pbeg;
	dek* pend;
};

void creation(DEK* d, int u) {
	d->pbeg = new dek;
	d->pbeg->x = u;
	d->pbeg->Next = d->pbeg->Head = NULL;
	d->pend = d->pbeg;

}


void addnacalo(DEK* d, int u) {
	dek* pv = new dek;
	pv->x = u;
	pv->Next = NULL;
	pv->Head = d->pbeg;
	d->pbeg->Next = pv;
	d->pbeg = pv;
}

void addconec(DEK* d, int u) {
	dek* pv = new dek;
	pv->x = u;
	pv->Head = NULL;
	pv->Next = d->pend;
	d->pend->Head = pv;
	d->pend = pv;
}

int dekkonec(DEK* d) {
	int temp = d->pend->x;
	dek* pv = d->pend;
	d->pend = d->pend->Next;
	delete pv;
	return temp;
}

int deknachalo(DEK* d) {
	int temp = d->pbeg->x;
	dek* pv = d->pbeg;
	d->pbeg = d->pbeg->Head;
	delete pv;
	return temp;
}

struct Node
{
	int data;
	Node *next;
};
struct Queue
{
	Node *first;
	Node *last;
};
void Creation(Queue *Q)
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
}

int Top(Queue *Q)
{
	return Q->first->next->data;
}
void Add(Queue *Q, int value)
{
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value;
	Q->last->next = NULL;
}
void Delete(Queue *Q)
{
	Q->first = Q->first->next;
}


int main() {
	setlocale(0, "");
	cout << "Введите 1-стек 2-очередь 3-дек" << endl;
	int p;
	cin >> p;
	if (p == 1) {
		stek *Mystek = new stek;
		Mystek->Head = NULL;
		cout << "Введите сколько элементов хотите добавить в стек" << endl;
		int r;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> r;
			add(r, Mystek);
		}
		show(Mystek);
		dele(Mystek);
		delete Mystek;
		Sleep(10000);
		system("cls");
		return main();
	}
	if (p == 2) {
		Queue Q;
		Creation(&Q);
		cout << "Введите сколько элементов хотите добавить в очередь" << endl;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			Add(&Q, a);
		}
		cout << "Очередь" << endl;
		for (int i = 0; i < N; i++) {
			cout << Top(&Q) << " ";
			Delete(&Q);
		}
		Sleep(10000);
		system("cls");
		return main();
	}
	if (p == 3) {
		DEK d;
		cout << "Введите количество элементов дека" << endl;
		int N;
		cin >> N;
		cout << "Введите первый элемент дека" << endl;
		int p;
		cin >> p;
		creation(&d, p);
		for (int i = 0; i < N - 1; i++) {
			int r;
			cout << "Введите элемент:" << " " << endl;
			cin >> r;
			cout << "Введите 1 если хотите добавить в конец 2-в начало" << " ";
			int u;
			cin >> u;
			if (u == 1) {
				addconec(&d, r);
			}
			if (u == 2) {
				addnacalo(&d, r);
			}
		}
		cout << "Введите 1-выборка с конца 2-с начала" << " ";
		int j;
		cin >> j;
		if (j == 1) {
			for (int i = 0; i < N; i++) {
				cout << dekkonec(&d) << endl;
			}
		}
		if (j == 2) {
			for (int i = 0; i < N; i++) {
				cout << deknachalo(&d) << endl;
			}
		}
		Sleep(20000);
		system("cls");
		return main();
	}
	cin.get();
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
