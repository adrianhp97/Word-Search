#include <fstream>
#include "Matriks.h"

using namespace std;

#ifndef PARSER_H
#define PARSER_H

class Parser : public Matriks{
	public:
		Parser();

	private:
		ifstream file;
};

#endif