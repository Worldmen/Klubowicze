#include <iostream>
#include <utility>

using namespace std;

void decToBin(bool **opinion, pair<int, int> *zeroOne, int m, int n) {
	for (int i = 0; i < n; i++) {
		zeroOne[i].first = 0;
		zeroOne[i].second = 0;
	}
	int opinionDec;
	for (int i = 0; i < m; i++) {
		cin >> opinionDec;
		for (int j = 0; j < n; j++) {
			if (opinionDec % 2) {
				zeroOne[j].second++;
				opinion[i][j] = 1;
			}
			else {
				zeroOne[j].first++;
				opinion[i][j] = 0;
			}
			opinionDec /= 2;
		}
	}
}

void showBoard(int m,int n, bool** board, pair<int,int>*zeroOne)
{
	system("cls");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	for (int j = 0; j < n; j++)
		cout << zeroOne[j].first << " ";
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << zeroOne[j].second << " ";
	cout << endl;
}

void condition(pair<int, int>*zeroOne, bool doable, bool* check, int n) {
	for (int i = 0; i < n; i++) {
		if (zeroOne[i].first == 1 || zeroOne[i].second == 1) {
			doable = false;
			return;
		}
		if (zeroOne[i].first == 0 || zeroOne[i].second == 0) {
			check[i] = false;
		}
		else
			check[i] = true;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	bool **opinion = new bool*[m];
	for (int i = 0; i < m; i++) {
		opinion[i] = new bool[n];
	}
	pair<int, int>*zeroOne = new pair<int, int>[n];
	decToBin(opinion, zeroOne, m, n);
	//showBoard(m, n, opinion, zeroOne);
	
	bool doable = true, *check = new bool[n];
	condition(zeroOne, doable, check, n);
	
	
	
	return 0;
}
