#include <iostream>
#include <string>
#include "Encode.h"

using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << HtmlEncode(str) << endl;
	}
}
