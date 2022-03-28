#include "lexer.h"

struct Condition {
	Condition(char s) : name(s), next() {}
	char name;
	std::map <char, Condition*> next;
};


std::string Lexer::spacecut(std::string inp) {
	std::string out = "";
	bool b = false;
	for (int i = 0; i < inp.size(); i++) {
		if (inp[i] == ' ') {
			if (b) {
                continue;
            }
			b = true;
		} else if (inp[i] == '\t') {
			continue;
		} else {
            b = false;
        }
		out += inp[i];
	}
	return out;
}


std::vector<std::pair<char, std::string> > Lexer::lexanalyze() {
	std::ifstream setup("setup.txt");
	std::ifstream reserved("reserved.txt");
	std::ifstream codefile("code1.txt");

	std::map<char, Condition*> states;
	for (auto i: "SADOPBC") {
		states[i] = new Condition(i);
	}

	std::vector<std::string> res;
	std::string line = "", code = "", lexeme = "";
	std::vector<std::pair<char, std::string> > tokens;
	std::pair<char, std::string> token;
	char cond1, cond2, symbol, state, oldstate;
	

	//turn code file into one string
	if (codefile.is_open()) {
		while (getline(codefile, line)) {
			code += spacecut(line);
		}
	}
	else {
		std::cout << "CodeNotFound\n";
	}
	std::cout << code;
	code += " ";
	if (reserved.is_open()) {
		while (getline(reserved, line)) {
			res.push_back(line);
		}
	}
	else {
		std::cout << "ReservedError\n";
	}


	if (setup.is_open()) {
		while (getline(setup, line)) {
			cond1 = line[0];
			if (line[1] == '\\') {
				cond2 = line[3];
				states[cond1]->next[line[2]] = states[cond2];
			}
			else if (line[1] == '[') {
				char l, r;
				l = line[2];
				r = line[4];
				cond2 = line[6];
				for (char i = l; i <= r; ++i) {
					states[cond1]->next[i] = states[cond2];
				}
			}
			else if (line[1] == '{') {
				cond2 = line.back();
				for (int i = 2; i < line.size() - 2; ++i) {
					states[cond1]->next[line[i]] = states[cond2];
				}

			}
		}

	}
	else {std::cout << "SetupfileError\n";
	}
	/*S - space #don't need lol
	D - digit
	O - operator #part-single
	P - punktuation #single
	A - consts 
	B - () #single
	C - [] #single

	R - reserved
	*/
	std::vector<char> singleconditions{ 'P', 'B', 'C' };
	std::vector<std::string> doubleoperators{ "--", "++", "+=", "-=", "/=", "*=", ">=", "<=", "==", "!=" , "%=", "//", "**", ">>", "<<"};

	//for (auto a : states['S']->next) {
	//	std::cout << std::endl << a.first << " " << a.second;
	//}

	state = 'S';
	oldstate = states['S']->next[code[0]]->name;
	lexeme = "";
	code += " ";
	for (int i = 0; i < code.size(); ++i) {
		symbol = code[i];
		oldstate = state;
		state = states[state]->next[symbol]->name;

		

		if(oldstate == 'O') {
			if (std::find(doubleoperators.begin(), doubleoperators.end(), lexeme + symbol) != doubleoperators.end()) {
				//token.first = oldstate;
				//token.second = lexeme + symbol;
				++i;
				lexeme += symbol;
				symbol = code[i];
				state = states[state]->next[symbol]->name;
			}
		}
		if (state != oldstate or oldstate == 'B' or oldstate == 'C' or oldstate == 'P' or oldstate == 'O') {
			token.first = oldstate;
			if (token.first == 'A') {
				if (std::find(res.begin(), res.end(), lexeme) != res.end()) {
					token.first = 'R';
				}
			}

			token.second = lexeme;
			if (lexeme != " ") {
				tokens.push_back(token);
				//std::cout << token.first << "   " << token.second << std::endl;
			}
			lexeme = "";
		}
		lexeme += symbol;
	}
	/*for (auto token : tokens) {
		std::cout << token.first << "   " << token.second << std::endl;
	}*/
	return tokens;
}