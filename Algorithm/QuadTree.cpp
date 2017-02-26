#include <iostream>
#include <string>

using namespace std;

int strIndex = 0;
string inputStr;// = "xbwxwbbwb";


string reverse() {
	char c = inputStr[strIndex++];
	 if (c == 'b' || c == 'w') {
		return string(1, c);
	}
	else {
		string upL = reverse();
		string upR = reverse();
		string downL = reverse();
		string downR = reverse();
		return "x" + downL + downR + upL + upR;
	}
}

int main() {
	int tCase;
	cin >> tCase;
	while (tCase > 0) {
		cin >> inputStr;
		cout << reverse() << endl;
		inputStr.clear();
		strIndex = 0;
		tCase--;
	}		
}