//Вариант 13 Задача.Янка
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef list <int>::iterator lit;

bool widesearch(vector<pair <int, int>>& Ribs, bool* satur, int N, int K, vector <list <int>> Graf)
{
	vector <int> node;
	for (int i = 0; i < 2 * N; i++)
	{
		if (!satur[i])
		{
			node.push_back(i);
		}
	}
	if (node.size() == 0)
	{
		return true;
	}
	int* IsVisited = new int[2 * N];
	int* Ancestors = new int[2 * N];
	for (int i = 0; i < 2 * N; i++)
	{
		IsVisited[i] = -1;
		Ancestors[i] = -1;
	}
	queue <int> Q;
	bool QControl = false;
	int ControlInt = -1;
	for (int i = 0; i < node.size(); i++)
	{
		IsVisited[node[i]] = 0;
		Q.push(node[i]);
		while (!Q.empty())
		{
			int Buff = Q.front();
			Q.pop();
			if (IsVisited[Buff] == 0)
			{
				for (lit j = Graf[Buff].begin(); j != Graf[Buff].end(); j++)
				{
					if (IsVisited[*j] == -1)
					{
						IsVisited[*j] = 1;
						Ancestors[*j] = Buff;
						Q.push(*j);
					}
				}
			}
			else
			{
				if (satur[Buff] == true)
				{
					for (int i = 0; i < Ribs.size(); i++)
					{
						if (Ribs[i].first == Buff)
						{
							IsVisited[Ribs[i].second] = 0;
							Ancestors[Ribs[i].second] = Buff;
							Q.push(Ribs[i].second);
							break;
						}
						else if (Ribs[i].second == Buff)
						{
							IsVisited[Ribs[i].first] = 0;
							Ancestors[Ribs[i].first] = Buff;
							Q.push(Ribs[i].first);
							break;
						}
					}
				}
				else
				{
					ControlInt = Buff;
					QControl = true;
					break;
				}
			}
		}
		if (QControl)
		{
			break;
		}
	}
	if (!QControl)
	{
		delete IsVisited;
		delete Ancestors;
		return true;
	}


	vector <pair <int, int>> IncreasingChain;
	int buff2 = ControlInt;
	while (Ancestors[buff2] != -1)
	{
		int buff3 = Ancestors[buff2];
		if (buff3 < buff2)
		{
			IncreasingChain.push_back(make_pair(buff3, buff2));
			buff2 = buff3;
		}
		else
		{
			IncreasingChain.push_back(make_pair(buff2, buff3));
			buff2 = buff3;
		}
	}
	satur[ControlInt] = true;
	satur[buff2] = true;

	for (int i = 0; i < IncreasingChain.size(); i++)
	{
		if (i % 2 == 0)
		{
			Ribs.push_back(IncreasingChain[i]);
		}
		else
		{
			for (vector <pair <int, int>>::iterator vit = Ribs.begin(); vit != Ribs.end(); vit++)
			{
				if (vit->first == IncreasingChain[i].first && vit->second == IncreasingChain[i].second)
				{
					Ribs.erase(vit);
					break;
				}
			}
		}
	}
	delete IsVisited;
	delete Ancestors;
	return false;
}

int main()
{
	setlocale(LC_ALL, "ru");
	ifstream fin("input.txt");
	int N, K;
	fin >> N >> K;
	int** Mass = new int* [N];
	cout << "Входной файл  n=5 , k=6" << endl;
	for (int i = 0; i < N; i++)
	{
		Mass[i] = new int[K];
		for (int j = 0; j < K; j++)
		{
			fin >> Mass[i][j];
			cout << Mass[i][j] << " ";
			Mass[i][j]--;
		}
		cout << endl;
	}
	fin.close();
	vector <list <int>> Graf(2 * N, list <int>());
	for (int i = 0; i < N; i++)
	{
		bool* flag = new bool[N] {false};
		for (int j = 0; j < K; j++)
		{
			if (!flag[Mass[i][j]])
			{
				flag[Mass[i][j]] = true;
				Graf[i].push_back(Mass[i][j] + N);
				Graf[Mass[i][j] + N].push_back(i);
			}
		}
		delete flag;
	}
	bool* satur = new bool[2 * N]{ false };
	vector<pair <int, int>> Ribs;
	for (int i = 0; i < N; i++)
	{
		for (lit j = Graf[i].begin(); j != Graf[i].end(); j++)
		{
			if (!satur[*j])
			{
				satur[*j] = true;
				satur[i] = true;
				Ribs.push_back(make_pair(i, *j));
				break;
			}
		}
	}
	bool flag = false;
	while (!flag)
	{
		flag = widesearch(Ribs, satur, N, K, Graf);
	}
	int* Result = new int[N];
	for (int i = 0; i < N; i++)
	{
		Result[Ribs[i].first] = Ribs[i].second;
	}
	cout << endl;
	cout << "Строка искомой расстановки" << endl;
	for (int i = 0; i < N; i++)
	{

		cout<< Result[i] - N + 1 << " ";
	}
	delete Result;
	delete satur;
	delete[]Mass;
	return 0;
}