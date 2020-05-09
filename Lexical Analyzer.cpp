#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

bool RealNumber(char* str)
{
	int i, len = strlen(str);
	int s = atoi(str);
	bool hasDecimal = false;
	

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if ((str[i] == '.') && ((str[i+1] >= 'A' && str[i+1] <= 'Z') || (str[i+1] >= 'a' && str[i+1] <= 'z')))
		{
			cout << "Error at ." << "  ";
		}
		if (!(s>=0 && s <=9 )&& str[i] != '.' ||
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
	int s = atoi(str);
	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {

		
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' && str[i] != '5'&& str[i] != '6' && str[i] != '7' && str[i] != '8'&& str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}
bool keyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") || !strcmp(str, "for") || !strcmp(str, "return")||
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
bool Boolean(char* str)
{
	if (!strcmp(str, "true") || !strcmp(str, "false"))
		return true;
	return false;
}
bool CompOperator(char* str)
{
	if (!strcmp(str, "==") || !strcmp(str, ">") || !strcmp(str, "<") || !strcmp(str, "<=") || !strcmp(str, ">="))
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
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return (false);
}
bool paren(char ch) {
	if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return false;
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
	int lp = 0, rp = 0;
	int t = 0;
	while (y <= n && x <= y)
	{
	
		if (str[y] == '"') {
			y += 1;
			cout << "<CHAR, ";
			while (str[y] != '"') {
				cout << str[y];
				y++;
			}
			cout <<">"<< endl;
			y++;
			x = y;
			
		}

		if (delimiter(str[y]) == false)
		{
			y++;
		}
		if (delimiter(str[y]) == true && x == y)
		{
			if (Operator(str[y])==true && Operator(str[y+1]) == false)
			{
				if (str[y] == '=') {
					cout << "<ASIGN>" << endl;
				}
				else {
					cout << "<ARITHMETIC, " << str[y] <<">"<< endl;

				}
				
			}
			if (paren(str[y]) == true )
			{
				if (str[y] == '(') {
					cout << "<LPAREN," << str[y] << ">"<<endl;
				}
				else if(str[y] == ')'){
					cout << "<RPAREN," << str[y] << ">" << endl;
				}
				else {
					cout << "<PAREN," << str[y] << ">" << endl;
				}
				
			}
			if (str[y] == ',')
			{
				cout << "<COMMA>" << endl;
			}
			if (Operator(str[y]) == true && Operator(str[y + 1]) == true)
			{
				if ((str[y] == str[y + 1])&&str[y]!='=') {
					cout << "<BITWISE," << str[y] << str[y + 1] << ">" << endl;
				}
				else {
					cout << "<COMPARE," << str[y] <<str[y+1]<< ">"<<endl;

				}
				
				y++;
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
				printf("\n");
			}

			else if (CompOperator(subStr) == true)
			{
				cout << "<COMPARE," << subStr << ">"<<endl;
			}


			else if (Integer(subStr) == true)
				printf("<INT ,%s>\n", subStr);

			else if (RealNumber(subStr) == true) 
				cout << "<FLOAT," << subStr << ">" << endl;
			
			else if (Boolean(subStr))
				cout << "<BOOL>" << endl;
				

			else if (Identifier(subStr) == true && delimiter(str[y - 1]) == false )
				printf("<ID,%s>\n", subStr);

			else if (Identifier(subStr) == false
				&& delimiter(str[y - 1]) == false) {
				//printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
				cout << "<INTEGER," << subStr[0] << ">\n"<<"<ID,";
				for (int a = 1; a < strlen(subStr); a++) {
					cout << subStr[a];
				}
				cout << ">"<<endl;

			}
				
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

