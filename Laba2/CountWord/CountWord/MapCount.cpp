#include "MapCount.h"

using namespace std;
void ToLower(string& str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
}

map<string, size_t> CreateWordsMap(istream& input)
{
	map<string, size_t> wordsMap;
	string word;
	while (input >> word)
	{
		ToLower(word);
		if (wordsMap.count(word))
		{
			++wordsMap[word];
		}
		else
		{
			wordsMap[word] = 1;
		}
	}

	return wordsMap;
}

string WordsMapToString(const map<string, size_t>& wordsMap)
{
	string resultStr;
	for (const auto& word : wordsMap)
	{
		resultStr += word.first + " - " + to_string(word.second) + '\n';
	}

	return resultStr;
}