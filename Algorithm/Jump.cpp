#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
#define MAX_SIZE 100

int testCase;
int gridSize;
int grid[MAX_SIZE][MAX_SIZE];
int cache[MAX_SIZE][MAX_SIZE];
bool flag = false;

int jumpGame(int x, int y) {
	if (x >= gridSize || y >= gridSize)		return 0;	
	if (cache[y][x] == 0) 		return 0;	

	if (x == gridSize - 1 && y == gridSize - 1) {
		flag = true;
		return 1;
	}		
	if (x + grid[y][x] < gridSize || y + grid[y][x] < gridSize) {
		cache[y][x] = jumpGame(x + grid[y][x], y);
		cache[y][x] = jumpGame(x, y + grid[y][x]);
	}

}
int main() {
	ifstream cin("inputJump.txt");	
	cin >> testCase;
	while (testCase > 0) {
		cin >> gridSize;
		memset(cache, -1, sizeof(cache));
		for (int y = 0; y < gridSize; y++) {
			for (int x = 0; x < gridSize; x++) {
				cin >> grid[y][x];				
			}		
		}		
		jumpGame(0, 0);
		if (flag)cout << "YES" << endl;
		else cout << "NO" << endl;			
		testCase--;
		flag = false;
	}
	cin.close();
	return 0;
}


/*
#include <iostream>
#include <fstream>

using namespace std;
#define MAX_SIZE 100

int testCase;
int gridSize;
int grid[MAX_SIZE][MAX_SIZE];
bool flag = false;

int jumpGame(int x, int y) {
if (x == gridSize - 1 && y == gridSize - 1) {
flag = true;
return 1;
}
else if(x >= gridSize || y >= gridSize) return 0;
else {
jumpGame(x + grid[y][x], y);
jumpGame(x, y + grid[y][x]);
}
}


int main() {
//ifstream cin("input.txt");

cin >> testCase;
while (testCase > 0) {
cin >> gridSize;
for (int y = 0; y < gridSize; y++) {
for (int x = 0; x < gridSize; x++) {
cin >> grid[y][x];
}
}
jumpGame(0, 0);
if (flag)cout << "YES" << endl;
else cout << "NO" << endl;
testCase--;
flag = false;
}

//cin.close();
return 0;
}
*/