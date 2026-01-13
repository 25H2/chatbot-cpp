#include "file_io.h"
#include <fstream>
using namespace std;
bool SaveToFile(const string& filename, const vector<QaRecord>& records) {
	ofstream out(filename);
	if (!out.is_open()) {
		return false;
	}
	for (size_t i = 0; i < records.size(); i++) {
		out << records[i].question << endl;
		out << records[i].answer << endl;
		out << endl;
	}
	return true;
}
bool LoadFromFile(const string& filename, vector<QaRecord>& out_records) {
	ifstream in(filename);
	if (!in.is_open()) {
		return false;
	}
	vector<QaRecord> tmp;
	while (true) {
		string q, a, sep;
		if (!getline(in, q)) {
			break;
		}
		if (!getline(in, a)) {
			return false;
		}
		getline(in, sep);
		tmp.push_back(QaRecord{ q, a });
	}
	out_records = tmp;
	return true;
}