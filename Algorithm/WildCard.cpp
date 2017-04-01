//최적화1
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
#define MAX_STRING 50
int testCase;
int cache[101][101];

string wild, src[MAX_STRING];

bool checkWildCard(int wildIndex, int srcIndex, int srcNum) {
	if (cache[wildIndex][srcIndex] == -1) return false;
	while (1) {
		if (wildIndex >= wild.size() || srcIndex >= src[srcNum].size()) break;
		else if (wild[wildIndex] == '?') {
			wildIndex++;  srcIndex++;
		}
		else if (wild[wildIndex] == src[srcNum][srcIndex]) {
			wildIndex++; srcIndex++;
		}
		else break;
	}
	if (wildIndex == wild.size() && srcIndex == src[srcNum].size())
		return true;

	if (wild[wildIndex] == '*') {
		for (int next = 0; next + srcIndex <= src[srcNum].size(); next++) {
			if (checkWildCard(wildIndex + 1, srcIndex + next, srcNum))
				return true;
		}
	}
	cache[wildIndex][srcIndex] = -1;
	return false;
}

void asciiSort(string input[MAX_STRING], int size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - 1; i++) {
			if (input[i].compare(input[i + 1]) > 0) {
				string temp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = temp;
			}
		}
	}
}

int main() {
	ifstream cin("inputWild.txt");
	cin >> testCase;
	while (testCase > 0) {
		int srcSize;
		cin >> wild >> srcSize;
		for (int i = 0; i < srcSize; i++) {
			cin >> src[i];
		}
		asciiSort(src, srcSize);
		for (int i = 0; i < srcSize; i++) {
			if (checkWildCard(0, 0, i))	cout << src[i] << endl;
			memset(cache, 0, sizeof(cache));
		}
		testCase--;
	}
	return 0;
}
/*
//최적화2
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
#define MAX_STRING 50
int testCase;
int cache[101][101];

string wild, src[MAX_STRING];

bool checkWildCard(int wildIndex, int srcIndex, int srcNum) {	
	if (cache[wildIndex][srcIndex] == -1) return false;
	while (1) {
		if (wildIndex >= wild.size() ||	srcIndex >= src[srcNum].size()) break;
		else if (wild[wildIndex] == '?') {
			return cache[wildIndex][srcIndex] = checkWildCard(wildIndex + 1, srcIndex + 1, srcNum);
		}
		else if (wild[wildIndex] == src[srcNum][srcIndex]) {
			return cache[wildIndex][srcIndex] = checkWildCard(wildIndex + 1, srcIndex + 1, srcNum);
		}
		else break;
	}
	if (wildIndex == wild.size() && srcIndex == src[srcNum].size())
		return true;

	if (wild[wildIndex] == '*') {
		if (checkWildCard(wildIndex + 1, srcIndex, srcNum)
			|| (srcIndex < src[srcNum].size() && checkWildCard(wildIndex, srcIndex + 1, srcNum)))
			return true;
		
	}
	cache[wildIndex][srcIndex] = -1;
	return false;
}

void asciiSort(string input[MAX_STRING], int size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - 1; i++) {
			if (input[i].compare(input[i + 1]) > 0) {
				string temp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = temp;
			}
		}
	}
}

int main() {
	ifstream cin("inputWild.txt");

	cin >> testCase;
	while (testCase > 0) {
		int srcSize;
		cin >> wild >> srcSize;
		for (int i = 0; i < srcSize; i++) {
			cin >> src[i];
		}
		asciiSort(src, srcSize);
		for (int i = 0; i < srcSize; i++) {
			if (checkWildCard(0, 0, i))	cout << src[i] << endl;
			memset(cache, 0, sizeof(cache));
		}
		testCase--;
	}
	return 0;
}
*/

/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int testCase;
#define MAX_STRING 50

bool checkWildCard(string wild, string src) {
	int index = 0;
	while (1) {
		 if (index >= wild.size() ||
				index >= src.size()) break;
		else if (wild[index] == '?') index++;
		else if (wild[index] == src[index]) index++;	
		else break;
	}
	if (index == wild.size() && index == src.size()	) 
		return true;
		
	if (wild[index] == '*') {
		for (int next = 0; next + index <= src.size(); next++) {
			if( checkWildCard(wild.substr(index + 1), src.substr(index + next)))
			return true;
		}
	}	
	return false;
}

void asciiSort(string input[MAX_STRING], int size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size-1; i++) {
			if (input[i].compare(input[i + 1]) > 0) {
				string temp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = temp;
			}
		}
	}
}

int main() {
	ifstream cin("inputWild.txt");
	string wild, src[MAX_STRING];
	
	cin >> testCase;
	while (testCase > 0) {
		int srcSize;
		cin >> wild>> srcSize;
		for (int i = 0; i < srcSize; i++) {
			cin >> src[i];				
		}	
		asciiSort(src, srcSize);
		for (int i = 0; i < srcSize; i++) {			
			if (checkWildCard(wild, src[i]))	cout << src[i] << endl;			
		}
		testCase--;
	}
}

*/