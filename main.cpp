#include "ChatBot.h"
#include "file_io.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
static void PrintMenu() {
	PrintSeparator();
	cout << "Чат бот (вопрос-ответ)" << endl;
	cout << "1) Добавить вопрос и ответ" << endl;
	cout << "2) Редактировать ответ" << endl;
	cout << "3) Редактировать вопрос" << endl;
	cout << "4) Удалить вопрос" << endl;
	cout << "5) Найти ответ по вопросу" << endl;
	cout << "6) Показать все вопросы" << endl;
	cout << "7) Сохранить в файл" << endl;
	cout << "8) Загрузить из файла" << endl;
	cout << "0) Выход" << endl;
	PrintSeparator();
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	vector<QaRecord> records;
	const string defaultFile = "qa_data.txt";
	while (true) {
		PrintMenu();
		int k;
		ReadIntInRange("Выберите пункт меню: ", 0, 8, k);
		if (k == 0) {
			cout << "Выход" << endl;
			break;
		}
		if (k == 1) {
			string q = ReadNonEmptyLine("Введите вопрос: ");
			int idx = FindIndexByQuestion(records, q);
			if (idx != -1) {
				cout << "Такой вопрос уже существует" << endl;
			}
			else {
				string a = ReadNonEmptyLine("Введите ответ: ");
				records.push_back({ q, a });
				cout << "Добавлено" << endl;
			}
		}
		else if (k == 2) {
			string q = ReadNonEmptyLine("Введите вопрос: ");
			int idx = FindIndexByQuestion(records, q);
			if (idx < 0) {
				cout << "Вопрос не найден" << endl;
			}
			else {
				string a = ReadNonEmptyLine("Введите новый ответ: ");
				records[idx].answer = a;
				cout << "Ответ обновлен" << endl;
			}
		}
		else if (k == 3) {
			string old_q = ReadNonEmptyLine("Введите текущий вопрос: ");
			int idx_old = FindIndexByQuestion(records, old_q);
			if (idx_old < 0) {
				cout << "Вопрос не найден" << endl;
			}
			else {
				string new_q = ReadNonEmptyLine("Введите новый вопрос: ");
				int idx_new = FindIndexByQuestion(records, new_q);
				if (idx_new != -1) {
					cout << "Нельзя: новый вопрос уже существует" << endl;
				}
				else {
					records[idx_old].question = new_q;
					cout << "Вопрос обновлен" << endl;
				}
			}
		}
		else if (k == 4) {
			string q = ReadNonEmptyLine("Введите вопрос для удаления: ");
			int idx = FindIndexByQuestion(records, q);
			if (idx < 0) {
				cout << "Вопрос не найден" << endl;
			}
			else {
				char confirm;
				cout << "Точно удалить? (y/n): ";
				cin >> confirm;
				cin.ignore(10000, '\n');
				if (confirm == 'y' || confirm == 'Y') {
					records.erase(records.begin() + idx);
					cout << "Удалено" << endl;
				}
				else {
					cout << "Удаление отменено" << endl;
				}
			}
		}
		else if (k == 5) {
			string q = ReadNonEmptyLine("Введите вопрос: ");
			string ans;
			if (FindAnswer(records, q, ans)) {
				cout << "Ответ: " << ans << endl;
			}
			else {
				cout << "Не знаю ответа на этот вопрос" << endl;
			}
		}
		else if (k == 6) {
			vector<string> questions = GetAllQuestions(records);
			if (questions.empty()) {
				cout << "Вопросов нет" << endl;
			}
			else {
				cout << "Вопросы: " << endl;
				for (size_t i = 0; i < questions.size(); i++) {
					cout << (i + 1) << ") " << questions[i] << endl;
				}
			}
		}
		else if (k == 7) {
			string filename = ReadLine("Имя файла (Enter = qa_data.txt): ");
			if (filename.empty()) {
				filename = defaultFile;
			}
			if (SaveToFile(filename, records)) {
				cout << "Сохранено" << endl;
			}
			else {
				cout << "Ошибка: не удалось сохранить файл" << endl;
			}
		}
		else if (k == 8) {
			string filename = ReadLine("Имя файла (Enter = qa_data.txt): ");
			if (filename.empty()) {
				filename = defaultFile;
			}
			vector<QaRecord> loaded;
			if (LoadFromFile(filename, loaded)) {
				records = loaded;
				cout << "Загружено записей: " << records.size() << endl;
			}
			else {
				cout << "Ошибка: не удалось загрузить файл" << endl;
			}
		}
		cout << "Нажмите Enter, чтобы вернуться в меню...";
		string dummy;
		getline(cin, dummy);
	}
	return 0;
}