#include <iostream>

using namespace std;
#define MAX_SIZE 30
int cache[MAX_SIZE][MAX_SIZE];
int bino2CountSize = 0;
int bino1CountSize = 0;
const int N = 25;
const int R = 10;

int bino(int n, int r) {
	bino1CountSize++;
	if (n == 0 || n == r) {
		return 0;
	}else {
		return bino(n - 1, r - 1) + bino(n - 1, r);
	}

}

int bino2(int n, int r) {
	bino2CountSize++;
	if (n == r | n == 0) {
		return 1;
	}else if (cache[n][r] != -1) {
		return cache[n][r];
	}
	else {
		cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
	}
}

int main() {
	bino(N, R);
	cout << "bino("<<N<<","<<R<<")Count:" << bino1CountSize << endl;
	
	memset(cache, -1, sizeof(cache));
	bino2(N, R);
	cout << "bino2(" << N << "," << R << ")Count:" << bino2CountSize << endl;
	return 0;

}