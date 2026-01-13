#include "utils.h"
#include <iostream>
#include <sstream>
using namespace std;
string ReadLine(const string& prompt) {
	cout << prompt;
	string s;
	getline(cin, s);
	return s;
}
string ReadNonEmptyLine(const string& prompt) {
	while (true) {
		string s = ReadLine(prompt);
		if (!s.empty()) {
			return s;
		}
		cout << "Ошибка: строка не должна быть пустой" << endl;
	}
}
bool ReadIntInRange(const string& prompt, int minValue, int maxValue, int& out) {
	while (true) {
		string s = ReadLine(prompt);
		stringstream ss(s);
		int x;
		char extra;
		if ((ss >> x) && !(ss >> extra)) {
			if (x >= minValue && x <= maxValue) {
				out = x;
				return true;
			}
			cout << "Ошибка: число должно быть от " << minValue << " до " << maxValue << endl;
		}
		else {
			cout << "Ошибка: введите целое число" << endl;
		}
	}
}
void PrintSeparator() {
	cout << "---------------" << endl;
}