#pragma once
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
map<string, size_t> CreateWordsMap(istream& input);
string WordsMapToString(const map<string, size_t>& wordsMap);