#include <iostream>
#include <thread>
#include "Matriks.h"
#include "Parser.h"
#include "SearchEngine.h"

using namespace std;

int main() {
	Parser matriksParser;
	SearchEngine engine(matriksParser, "cb");
	return 0;
}

//g++ WordSearch.cpp Matriks.cpp SearchEngine.cpp Parser.cpp -o a -std=c++11