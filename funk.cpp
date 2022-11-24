#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

float power(float a, int b) {
	float s = 1.0;
	for (int i = 0; i < b; i++) {
		s *= a;
	}
	return s;
}

bool CHECKERTYPE(string a, int b) {
	string alphabet = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	bool ans = true;
	int i = 0;
	while (ans && i < a.length())
	{
		if (alphabet.find(a[i]) > b) {
			ans = false;
		}
		i++;
	}
	return ans;
}

string PEREVODTO(int a, int n) {
	string alphabet = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	if (a < n) {
		string b = "";
		b += alphabet[a];
		return b;
	}
	else {
		return PEREVODTO(a / n, n) + alphabet[a % n];
	}
}

int PEREVODTO10(string a, int b) {
	string alphabet = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	int n = 0,
		i = a.length();
	if (CHECKERTYPE(a, b)) {
		while (i > 0) {
			i--;
			n += alphabet.find(a[i]) * power(b, a.length() - i - 1);
		}
	}
	else {
		cout << "Wrong input!" << endl;
	}

	return n;
}

void Five7() {
	string Number1,
		Number2,
		Inp,
		Operation,
		Answ,
		Primer;
	bool An;
	ifstream f1;
	ofstream f2;
	f1.open("FN1.txt");
	f2.open("FN2.txt");
	//ofstream f2;
	while (f1 >> Primer) {
		Number1 = "";
		Number2 = "";
		Operation = "";
		Answ = "";
		An = false;
		for (int i = 0; i < Primer.length(); i++) {
			if (Operation == "" && Primer[i] != '+' && Primer[i] != '-' && Primer[i] != '=' && Primer[i] != '*') {
				Number1 += Primer[i];
			}
			else if (Primer[i] == '=') {
				An = true;
			}
			else if (An) {
				Answ += Primer[i];
			}
			else if (Operation == "" && !(Primer[i] != '+' && Primer[i] != '-' && Primer[i] != '=' && Primer[i] != '*')) {
				Operation = Primer[i];
			}
			else if (Operation != "" && Primer[i] != '+' && Primer[i] != '-' && Primer[i] != '=' && Primer[i] != '*') {
				Number2 += Primer[i];
			}
		}
		An = false;
		if (Operation == "+") {
			if (PEREVODTO10(Answ, 12) == (PEREVODTO10(Number1, 12) + PEREVODTO10(Number2, 12))) An = true;
			else An = false;
		}
		else if (Operation == "-") {
			if (PEREVODTO10(Answ, 12) == (PEREVODTO10(Number1, 12) - PEREVODTO10(Number2, 12))) An = true;
			else An = false;
		}
		else if (Operation == "*") {
			if (PEREVODTO10(Answ, 12) == (PEREVODTO10(Number1, 12) * PEREVODTO10(Number2, 12))) An = true;
			else An = false;
		}
		if (An) {
			f2 << Primer << " +" << endl;
		}
		else {
			f2 << Primer << " -" << endl;
		}
	}
	f1.close();
	f2.close();
}

void RandMass(int*& a, int N, int b) {
	srand(time(0));
	for (int i = 0; i < N; i++) {
		a[i] = rand() % b;
	}
}

void IntSwap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void SortEasyCho(int*& a, int N) {
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				IntSwap(a[j], a[i]);
			}
		}
	}
}

void MassOutput(int* a, int N) {
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Sort7() {
	int N;
	cout << "Type N - len of mass" << endl;
	cout << "-> ";
	cin >> N;
	int* a = new int[N];
	RandMass(a, N, 100);
	MassOutput(a, N);
	SortEasyCho(a, N);
	MassOutput(a, N);
	delete[]a;
}

int BinSearch(int* a, int N, int searcher) {
	int L, R, M;
	L = 0;
	R = N - 1;
	while (L < R) {
		M = (L + R) / 2;
		if (a[M] < searcher)
			L = M + 1;
		else
			R = M;
	}
	if (a[L] == searcher) return L;
	else return -1;
}

void Sort13() {
	int N, X, i, Numer = 0;
	cout << "Type len of mass!" << endl;
	cout << "-> ";
	cin >> N;
	cout << "Type what to find!" << endl;
	cout << "-> ";
	cin >> X;
	int* a = new int[N];
	RandMass(a, N, 10);
	SortEasyCho(a, N);
	MassOutput(a, N);
	i = BinSearch(a, N, X);
	while (a[i] == X && i < N) {
		i++;
		Numer++;
	}
	cout << "There are " << Numer << " of " << X << endl;
	delete[]a;
}