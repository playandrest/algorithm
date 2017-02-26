#include <iostream>
#include <fstream>
using namespace std;

#define MAX_TYPE 100

int testCase;
int totalMoney;
int coinTypeSize;
int coinType[MAX_TYPE];

int tNum = 0;

int splitMoney(int money, int coinSize) {

	if (money == 0) {
		tNum++;
		return 0;
	}

	//if(money > coinType[coinSize])
	
}


int main() {
	ifstream cin("inputCoin.txt");
	cin >> testCase;
	while (testCase > 0) {
		cin >> totalMoney;
		cin >> coinTypeSize;
		for (int i = 0; i < coinTypeSize; ++i) {
			cin >> coinType[i];
		}
		splitMoney(totalMoney, coinTypeSize);
		cout << tNum << endl;
		tNum = 0;
		testCase--;
	}


}