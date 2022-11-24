#include <iostream>
#include "Header.h"

using namespace std;

void main() {
	string Inp = "-";
	while (Inp != "0") {
		cout << "Type what do you need!" << endl;
		cout << "1 - Five7" << endl;
		cout << "2 - Sort7" << endl;
		cout << "3 - Sort13" << endl;
		cout << "-> ";
		cin >> Inp;
		if (Inp == "1") {
			Five7();
		}
		else if (Inp == "2") {
			Sort7();
		}
		else if (Inp == "3") {
			Sort13();
		}
	}
}