#include "Encode.h"

using namespace std;
string HtmlCharEncode(char ch)
{
	switch (ch)
	{
	case '<':
		return "&lt;";
	case '>':
		return "&gt;";
	case '"':
		return "&quot;";
	case '\'':
		return "&apos;";
	case '&':
		return "&amp;";
	default:
		return string(1, ch);
	}
}

string HtmlEncode(const std::string& text)
{
	string result;
	for (char ch : text)
	{
		result += HtmlCharEncode(ch);
	}
	return result;
}