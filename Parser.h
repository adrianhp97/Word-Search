#include <fstream>
#include "Matriks.h"

using namespace std;

#ifndef PARSER_H
#define PARSER_H

class Parser {
	public:
		Parser();
		Matriks getMatriks();

	private:
		Matriks data;
		ifstream file;
};

#endif