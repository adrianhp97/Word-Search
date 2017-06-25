#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include "Matriks.h"
#include "Parser.h"
#include "SearchEngine.h"

using namespace std;

int nProcess;
int nThread;

void forkProgram(SearchEngine thisMatriks, int numberProcess);

int main() {
	Parser matriksParser;
	string inputWord;

	cout << "Matrix of Word" << endl;
	matriksParser.printMatriks();
	cout << "Number of process: ";
	cin >> nProcess;
	cout << "Number of thread: ";
	cin >> nThread;
	cout << "Find word: ";
	cin >> inputWord;
	
	SearchEngine engine(matriksParser, inputWord);

	forkProgram(engine, nProcess);
	return 0;
}

void forkProgram(SearchEngine thisMatriks, int numberProcess) {
	pid_t pid;
	if (numberProcess <= 1) {
		
	} else {
		pid = fork();
		if (numberProcess%2 == 0) {
			if (pid >= 0) {
				forkProgram(thisMatriks, numberProcess/2);
			}
			else {
				cout << "Failed to fork" << endl;
			}
		} else {
			if (pid == 0) {
				forkProgram(thisMatriks, numberProcess/2);
			}
			else if (pid > 0) {
				forkProgram(thisMatriks, numberProcess/2 + 1);
			}
			else {
				cout << "Failed to fork" << endl;
			}
		}
	}
}

//g++ WordSearch.cpp Matriks.cpp SearchEngine.cpp Parser.cpp -o a -std=c++11