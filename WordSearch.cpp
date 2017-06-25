#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include "Matriks.h"
#include "Parser.h"
#include "SearchEngine.h"

using namespace std;

void forkProgram(SearchEngine thisMatriks, int numberProcess, int numberThread);

int main() {
	Parser matriksParser;
	SearchEngine engine(matriksParser, "cb");	
	int n;
	cin >> n;
	forkProgram(engine, n, 5);
	return 0;
}

void forkProgram(SearchEngine thisMatriks, int numberProcess, int numberThread) {
	pid_t pid;
	if (numberProcess <= 1) {
		//fungsi
		cout << "process" << endl;
	} else {
		pid = fork();
		if (numberProcess%2 == 0) {
			if (pid >= 0) {
				forkProgram(thisMatriks, numberProcess/2, numberThread);
			}
			else {
				cout << "Failed" << endl;
			}
		} else {
			if (pid == 0) {
				forkProgram(thisMatriks, numberProcess/2, numberThread);
			}
			else if (pid > 0) {
				forkProgram(thisMatriks, numberProcess/2 + 1, numberThread);
			}
			else {
				cout << "Failed" << endl;
			}
		}
	}
}

//g++ WordSearch.cpp Matriks.cpp SearchEngine.cpp Parser.cpp -o a -std=c++11