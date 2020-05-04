#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

bool RealNumber(char* str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}

bool Integer(char* str)
{
	int i, len = strlen(str);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}
bool keyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||
		!strcmp(str, "continue") || !strcmp(str, "int")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "return") || !strcmp(str, "char")
		|| !strcmp(str, "case") || !strcmp(str, "char")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "typedef")
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
		|| !strcmp(str, "void") || !strcmp(str, "static")
		|| !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}
bool Operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=')
		return (true);
	return (false);
}
bool delimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return (false);
}
bool Identifier(char* str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || delimiter(str[0]) == true)
		return (false);
	return (true);
}
void func(const char* str, int n)
{
	int i = 0, x = 0, y = 0;
	while (y <= n && x<=y)
	{
		if (delimiter(str[y]) == false)
		{
			y++;
		}
		if (delimiter(str[y]) == true && x == y)
		{
			if (Operator(str[y])==true)
			{
				cout << "Arithmetic operator " << str[y] << endl;
			}
			y++;
			x = y;

		}
		else if (delimiter(str[y]) == true && x!=y ||( y==n && x!=y))
		{
			char* subStr = (char*)malloc(sizeof(char) * ((y-1) - x + 2));
			for (int i = x; i <= y-1; i++)
				subStr[i - x] = str[i];
			subStr[(y-1) - x + 1] = '\0';



			if (keyword(subStr) == true) {
				for (int i = 0; i < strlen(subStr); i++)
					putchar(toupper(subStr[i]));
				printf("'%s'\n", subStr);
			}
				

			else if (Integer(subStr) == true)
				printf("INT :%s\n", subStr);

			else if (RealNumber(subStr) == true)
				printf("'%s' IS A REAL NUMBER\n", subStr);

			else if (Identifier(subStr) == true
				&& delimiter(str[y - 1]) == false)
				printf("'%s' IS A VALID IDENTIFIER\n", subStr);

			else if (Identifier(subStr) == false
				&& delimiter(str[y - 1]) == false)
				printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
			x = y;
		}
		i++;
	}
}

int main()
{
	cout << "Lexical Analyzer <input file name>" << endl;
	ifstream fin;
	fin.open("program.txt");
	string line;
	while (fin)
	{
		getline(fin, line);
		
		//char str[100];
		int len = line.length();
		

		func(line.c_str(), len);
		
	}
	fin.close();
}

