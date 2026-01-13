#pragma once
#include <string>
#include <vector>
struct QaRecord {
	std::string question;
	std::string answer;
};
int FindIndexByQuestion(const std::vector<QaRecord>& records, const std::string& question);
bool AddRecord(std::vector<QaRecord>& records, const std::string& question, const std::string& answer);
bool EditAnswer(std::vector<QaRecord>& records, const std::string& question, const std::string& new_answer);
bool EditQuestion(std::vector<QaRecord>& records, const std::string& old_question, const std::string& new_auestion);
bool RemoveRecord(std::vector<QaRecord>& records, const std::string& question);
bool FindAnswer(const std::vector<QaRecord>& records, const std::string& question, std::string& out_answer);
std::vector<std::string> GetAllQuestions(const std::vector<QaRecord>& records);