#include <iostream>

using namespace std;

long long unsigned int DCSum(int n) {
	if (n == 1) return 1;
	else if (n % 2 == 1) return  DCSum(n - 1) + n;
	else return 2 * DCSum(n / 2) + n*n / 4;

}

long long unsigned int sum(int n) {
	if (n == 1) return 1;
	else return  (long long int)sum(n - 1) + n;
}

long long unsigned int easySum(int n) {
	return  (long long int)n*(n + 1) / 2;
}

void main() {
	long long int N = 50000; //1억
	cout <<"1부터 "<< N << "까지의 합: " <<(long long int) DCSum(N) << endl;
	//cout << "1부터 " << N << "까지의 합: " << (long long int)sum(N) << endl;
	cout << "1부터 " << N << "까지의 합: " << (long long int)easySum(N) << endl;	

}