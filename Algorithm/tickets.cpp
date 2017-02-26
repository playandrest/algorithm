#include <iostream>

using namespace std;


void main()
{
	int testCase, coinSize;
	cin >> testCase;
	for (int n = 1; n <= testCase; ++n)
	{
		int money, coinSize, coinType[100];
		cin >> money >> coinSize;		
		for (int i = 0; i < coinSize; i++) 
		{
			cin >> coinType[i];
			cout << coinType[i]<<endl;
		}
		
	}

}