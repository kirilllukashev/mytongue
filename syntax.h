#pragma once
#include "lexer.h"

#include <vector>
#include <string>
#include <set>
#include <map>
class Syntax
{
public:
	Syntax(std::vector<std::pair<char, std::string> > tokens);
	std::vector<std::pair<char, std::string> > tokens_;

	void get_lexeme();
	std::pair<char, std::string> next_lexeme();
	std::pair<char, std::string> lex;
	std::vector <std::string> pr2_ = {"++", "--", "+", "-", "*", "&", "!"};
	std::vector <std::string> pr13_ = { "=", "+=", "-=", "/=", "*=", "%=", "^=", "&=", "|=", ">=", "<=" };

	bool begin();
	long token_index = 0;
private:
	void PROGRAM();

	void STRUCTS();
	void STRUCT();
	void STRUCTBLOCK();
	void STRUCTDESCRIPTION();

	void FUNCTIONS();
	void RETURN();
	void FUNCTIONPROTOTYPE();
	void FUNCTION();

	void STRUCTFUNCTION();
	void MAINFUNCTION();
	void STRUCTNAME();

	void PARAMETRS();

	void GLOBALDESCRIPTION();
	void GLOBALDESCRIPTIONS();
	void DESCRIPTION();

	void DIMENSION();

	void BLOCKOPERATORS();
	void OPERATORS();
	void OPERATOR();
	void OUTOPERATOR();
	void INOPERATOR();

	void ENUM();
	void IF();
	void FOR();
	void WHILE();
	void DOWHILE();
	void EXPRESSION();

	void DEFINITION();
	void NAME();

	void TYPE();
	void SIMPLETYPE();

	void PRIORITY1();
	void PRIORITY2();
	void PRIORITY3();
	void PRIORITY4();
	void PRIORITY5();
	void PRIORITY6();
	void PRIORITY7();
	void PRIORITY8();
	void PRIORITY9();
	void PRIORITY10();
	void PRIORITY11();
	void PRIORITY12();
	void PRIORITY13();
};

