#include <iostream>
#include <utility>
using namespace std;

void decToBin(bool **opinion, pair<int,int> *zeroOne, int m, int n){
	for (int i = 0; i < n; i++){
		zeroOne[i].first = 0;
		zeroOne[i].second = 0;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	bool **opinion = new bool*[m];
	for (int i = 0; i < m; i++){
		opinion[i] = new bool[n];
	}
	pair<int, int>*zeroOne = new pair<int, int>[n];
	decToBin(opinion, zeroOne, m, n);

	return 0;
}
