#include "chatbot.h"
using namespace std;
int FindIndexByQuestion(const vector<QaRecord>& records, const string& question) {
	for (size_t i = 0; i < records.size(); i++) {
		if (records[i].question == question) {
			return static_cast<int>(i);
		}
	}
	return -1;
}
bool AddRecord(vector<QaRecord>& records, const string& question, const string& answer) {
	if (FindIndexByQuestion(records, question) != -1) {
		return false;
	}
	records.push_back(QaRecord{ question, answer });
	return true;
}
bool EditAnswer(vector<QaRecord>& records, const string& question, const string& new_answer) {
	int idx = FindIndexByQuestion(records, question);
	if (idx < 0) {
		return false;
	}
	records[idx].answer = new_answer;
	return true;
}
bool EditQuestion(vector<QaRecord>& records, const string& old_question, const string& new_question) {
	int idx = FindIndexByQuestion(records, old_question);
	if (idx < 0) {
		return false;
	}
	if (FindIndexByQuestion(records, new_question) != -1) {
		return false;
	}
	records[idx].question = new_question;
	return true;
}
bool RemoveRecord(vector<QaRecord>& records, const string& question) {
	int idx = FindIndexByQuestion(records, question);
	if (idx < 0) {
		return false;
	}
	records.erase(records.begin() + idx);
	return true;
}
bool FindAnswer(const vector<QaRecord>& records, const string& question, string& out_answer) {
	int idx = FindIndexByQuestion(records, question);
	if (idx < 0) {
		return false;
	}
	out_answer = records[idx].answer;
	return true;
}
vector<string> GetAllQuestions(const vector<QaRecord>& records) {
	vector<string> result;
	for (size_t i = 0; i < records.size(); i++) {
		result.push_back(records[i].question);
	}
	return result;
}