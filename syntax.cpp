#include "syntax.h"
#include <algorithm>

Syntax::Syntax(std::vector<std::pair<char, std::string> > tokens) : tokens_(tokens) {}

void Syntax::get_lexeme() {
	lex = tokens_[token_index++];
}
std::pair<char, std::string> Syntax::next_lexeme() {
	return tokens_[token_index + 1];
}
bool Syntax::begin(){
	get_lexeme();
	PROGRAM();
//	return false;
}
void Syntax::PROGRAM() {
	MAINFUNCTION();
}

void Syntax::STRUCTS() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::STRUCT() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::STRUCTBLOCK() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::STRUCTDESCRIPTION() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::FUNCTIONS() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::RETURN() {
	if (lex.second == "return") {
		get_lexeme();
		if (lex.second == ";") {}
		else {
			EXPRESSION();
			get_lexeme();
			if (lex.second == ";") {}
		}

	}
}
void Syntax::FUNCTIONPROTOTYPE() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::FUNCTION() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::STRUCTFUNCTION() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::MAINFUNCTION() {
	if (lex.second == "main") {
		get_lexeme();
		if (lex.second == "(") {
			get_lexeme();
			if (lex.second == ")") {
				get_lexeme();
				BLOCKOPERATORS();
			}
		}
	}
}
void Syntax::STRUCTNAME() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::PARAMETRS() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::GLOBALDESCRIPTION() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::GLOBALDESCRIPTIONS() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::DESCRIPTION() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::DIMENSION() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::BLOCKOPERATORS() {
	if (lex.second == "{") {
		get_lexeme();
		OPERATORS();
		//тут вставл€ю гетлексему, хз, может не надо будет
		get_lexeme();
		if (lex.second == "}") {
		}
	}
}
void Syntax::OPERATORS() {
	OPERATOR();
	if (next_lexeme().second == "}") {}
	else {
		get_lexeme();
		OPERATORS();
	}
}
void Syntax::OPERATOR() {
	if (lex.second == "return") {
		RETURN();
	}
}
void Syntax::OUTOPERATOR() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::INOPERATOR() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::ENUM() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::IF() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::FOR() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::WHILE() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::DOWHILE() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::EXPRESSION() {
	PRIORITY13();
}

void Syntax::DEFINITION() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::NAME() {
	if (lex.first == 'A') {
	}
	else {

	}
}

void Syntax::TYPE() {
	std::cout << "Not Implemented" << std::endl;
}
void Syntax::SIMPLETYPE() {
	std::cout << "Not Implemented" << std::endl;
}

void Syntax::PRIORITY1() {
	if (lex.second == "(") {
		get_lexeme();
		EXPRESSION();
		get_lexeme();
		if (lex.second == ")") {

		}
		else {

		}
	}
	else {
		NAME();
		get_lexeme();
		if (lex.second == "(") {
			get_lexeme();
			if (lex.second == ")") {

			}
			else {
				EXPRESSION();
				get_lexeme();
				if (lex.second == ")") {

				}
				else {
					//error
				}
			}
		}
	}

}
void Syntax::PRIORITY2() {
	if (find(pr2_.begin(), pr2_.end(), lex.second) != pr2_.end()) {
		get_lexeme();
		PRIORITY2();
	}
	else {
		PRIORITY1();
	}
}
void Syntax::PRIORITY3() {
	PRIORITY2();
	get_lexeme();
	if (lex.second == "*" or lex.second == "/" or lex.second == "%") {
		get_lexeme();
		PRIORITY3	();
	}
}
void Syntax::PRIORITY4() {
	PRIORITY3();
	get_lexeme();
	if (lex.second == "+" or lex.second == "-") {
		get_lexeme();
		PRIORITY4();
	}
}
void Syntax::PRIORITY5() {
	PRIORITY4();
	get_lexeme();
	if (lex.second == "<<" or lex.second == ">>") {
		get_lexeme();
		PRIORITY5();
	}
}
void Syntax::PRIORITY6() {
	PRIORITY5();
	get_lexeme();
	if (lex.second == "<" or lex.second == ">" or lex.second == "<=" or lex.second == ">=") {
		get_lexeme();
		PRIORITY6();
	}
}
void Syntax::PRIORITY7() {
	PRIORITY6();
	get_lexeme();
	if (lex.second == "==" || lex.second == "!=") {
		get_lexeme();
		PRIORITY7();
	}
}
void Syntax::PRIORITY8() {
	PRIORITY7();
	get_lexeme();
	if (lex.second == "&") {
		get_lexeme();
		PRIORITY8();
	}
}
void Syntax::PRIORITY9() {
	PRIORITY8();
	get_lexeme();
	if (lex.second == "^") {
		get_lexeme();
		PRIORITY9();
	}
}
void Syntax::PRIORITY10() {
	PRIORITY9();
	get_lexeme();
	if (lex.second == "|") {
		get_lexeme();
		PRIORITY10();
	}
}
void Syntax::PRIORITY11() {
	PRIORITY10();
	get_lexeme();
	if (lex.second == "&&") {
		get_lexeme();
		PRIORITY11();
	}
}
void Syntax::PRIORITY12() {
	PRIORITY11();
	get_lexeme();
	if (lex.second == "||") {
		get_lexeme();
		PRIORITY12();
	}
}
void Syntax::PRIORITY13() {
	PRIORITY12();
	if (std::find(pr13_.begin(), pr13_.end(), lex.second) != pr13_.end()) {
		get_lexeme();
		PRIORITY13();
	}
	else {
	}
}