#include "lexer.h"
#include "syntax.h"

int main() {
	Lexer l;
	Syntax syntax = Syntax(l.lexanalyze());
	syntax.begin();
	return 0;
}