#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <regex>
#include <vector>

class Lexer {
public:
	std::vector<std::pair<char, std::string> > lexanalyze();
private:
    std::string spacecut(std::string inp);
};