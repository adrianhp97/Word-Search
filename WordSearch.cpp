#include <iostream>
#include <thread>
#include "Matriks.h"
#include "Parser.h"

using namespace std;

int main() {
	Parser matriksParser;
	Matriks wordMatriks(matriksParser.getMatriks());
	wordMatriks.printMatriks();
	return 0;
}