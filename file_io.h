#pragma once
#include <string>
#include <vector>
#include "ChatBot.h"
bool SaveToFile(const std::string& filename, const std::vector<QaRecord>& records);
bool LoadFromFile(const std::string& filename, std::vector<QaRecord>& out_records);