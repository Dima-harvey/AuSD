#include "pch.h"
#include <iostream>
#include <windows.h>
#include <list>
#include <ctime>
using namespace std;

struct stek {
	char x;
	stek* Next, *Head;
};

void add(char x, stek*& Mystek) {
	stek* temp = new stek;
	temp->x = x;
	temp->Next = Mystek->Head;
	Mystek->Head = temp;
}

void show(stek* Mystek) {
	stek* temp = Mystek->Head;
	cout << temp->x << " ";
	temp = temp->Next;
}

void dele(stek* Mystek) {
	stek* temp = Mystek->Head->Next;
	delete Mystek->Head;
	Mystek->Head = temp;
}

struct Node
{
	int data;
	Node* next;
};
struct Queue
{
	Node* first;
	Node* last;
};
void Creation(Queue* Q)
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
}

int Top(Queue* Q)
{
	return Q->first->next->data;
}

void Add(Queue* Q, int value)
{
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value;
	Q->last->next = NULL;
}
void Delete(Queue* Q)
{
	Q->first = Q->first->next;
}

struct dek {
	char x;
	dek* Next;
	dek* Head;
};
struct DEK {
	dek* pbeg;
	dek* pend;
};

void creation(DEK* d, char u) {
	d->pbeg = new dek;
	d->pbeg->x = u;
	d->pbeg->Next = d->pbeg->Head = NULL;
	d->pend = d->pbeg;

}


void addnacalo(DEK* d, char u) {
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

char dekkonec(DEK* d) {
	char temp = d->pend->x;
	dek* pv = d->pend;
	d->pend = d->pend->Next;
	delete pv;
	return temp;
}

char deknachalo(DEK* d) {
	char temp = d->pbeg->x;
	dek* pv = d->pbeg;
	d->pbeg = d->pbeg->Head;
	delete pv;
	return temp;
}

int i = 1;
int h = 1;

int main() {
	setlocale(LC_ALL, "rus");
	list<int> numbers = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	list<int> number1 = { 1,2,3,4,5,6,7,8,9,10};
	int R = 0;
	int L = 0;
	int T = 0;
	int N = 6;
	for (;;) {
		srand(time(NULL));
		int k = rand() % 3 + 1;
		if (k == 1) {
			Queue Q;
			Creation(&Q);
			for (i = 1; i < N; i++) {
				Add(&Q, i);
			}
			cout << "Пришли на пересдачу" << endl;
			srand(time(NULL));
			 k = rand() % 3 + 1;
			Sleep(2000);
			if (k == 1) {
				i++;
				Add(&Q, i);
				Sleep(2000);
				cout << "Дошли опаздавшие" << endl;
			}
			i--;
			 k = rand() % 2 + 1;
			if (k = 2) {
				h++;
				Sleep(2000);
				Delete(&Q);
				cout << "Студент отправился на пересдачу" << endl;
			}
			h++;
			Sleep(2000);
			cout << "Студент отправился на пересдачу" << endl;
			Sleep(2000);
			cout << "Cтоят в очереди" << endl;
			Sleep(2000);
			Delete(&Q);
			Sleep(3000);
			system("cls");
			
		}

		if (k == 2) {
			cout << "-Добрый день!!!" << endl;
			cout << "-На столе 19 билетов, тяните билет сверву или снизу" << endl;
			 k = rand() % 2 + 1;
			 Sleep(3000);
			if (k == 1){
				cout << "Пожалуй,возьму снизу" << endl;
				R = numbers.front();
				numbers.pop_front(); 
			}
			else {
				cout << "Пожалуй,возьму сверху" << endl;
				Sleep(3000);
				R = numbers.back();
				numbers.pop_back();
			}

			Sleep(3000);
			system("cls");
		}
		if (k == 3) {
			Queue Q1;
			Creation(&Q1);
			int answer = 0;
			cout << "-Возьмите задачу сверху" << endl;
			T = number1.back();
			Sleep(3000);
			for (int i = 1; i <= h; i++) {
				Add(&Q1,i);
			}
			int y = Top(&Q1);

			if ((answer = rand() % 10 )>4) {
				Sleep(3000);
				cout << "Студент сдал" << endl;
				numbers.push_front(R);
				number1.push_front(T);
				Delete(&Q1);

			}
			else {
				cout << "Студент не сдал, пошёл снова в конец очереди для пересдачи" << endl;
				Sleep(3000);
				numbers.push_front(R);
				number1.push_front(T);
				Delete(&Q1);
				N++;
			}
			Sleep(3000);
			system("cls");
		}

	}
	return 0;
}
