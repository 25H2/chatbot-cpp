#pragma once
#include <string>
std::string ReadLine(const std::string& prompt);
std::string ReadNonEmptyLine(const std::string& prompt);
bool ReadIntInRange(const std::string& prompt, int minValue, int maxValue, int& out);
void PrintSeparator();