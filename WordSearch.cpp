#include <iostream>
#include <thread>
#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include "src/Matriks.h"
#include "src/Parser/Parser.h"
#include "src/SearchEngine/SearchEngine.h"

using namespace std;

int nProcess;
int nThread;

void forkProgram(SearchEngine thisMatriks, int numberProcess);
void threadProgram(SearchEngine threadx);
void threadInit(SearchEngine thisMatriks, int methodProcessNum);


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
		if (nProcess < 8) {
			for (int idx = 1; idx <= 8; idx++) {
				if (idx % nProcess == getpid() % nProcess) {
					threadInit(thisMatriks, idx-1);
				}
			}
		} else {
			threadInit(thisMatriks, getpid() % 8);
		}
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

void threadProgram(SearchEngine threadx) {
	int iteratorSearch = round((float)threadx.getNbElmnt()/(float)nThread);
	int startIdx = (iteratorSearch*threadx.getThreadNum());


	switch(threadx.getProcessNum()) {
		case 0 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchRowTop(idx % threadx.getNbElmnt());
			}
			break;
		}
		case 1 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchRowDown(idx % threadx.getNbElmnt());
			}
			break;
		}
		case 2 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchColTop(idx % threadx.getNbElmnt());
			}
			break;
		}
		case 3 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchColDown(idx % threadx.getNbElmnt());
			}
			break;
		}
		case 4 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchDiagonalRTop(0,0);
			}
			break;
		}
		case 5 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchDiagonalRDown(0,0);
			}
			break;
		}
		case 6 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchDiagonalLTop(0,0);
			}
			break;
		}
		case 7 : {
			for (int idx = startIdx; idx < startIdx + iteratorSearch; idx++) {
				threadx.searchDiagonalLDown(0,0);
			}
			break;
		}
	}
}

void threadInit(SearchEngine thisMatriks, int methodProcessNum) {
	vector<thread> threadData;
	thisMatriks.setProcessNum(methodProcessNum);

	for(int idx = 0; idx < nThread; idx++){
		thisMatriks.setThreadNum(idx);
		threadData.push_back(thread(threadProgram, thisMatriks));
	}
	for(int idx = 0; idx < nThread; idx++){
		threadData[idx].join();
	}
}

//g++ WordSearch.cpp src/Matriks.cpp src/SearchEngine/SearchEngine.cpp src/Parser/Parser.cpp -o a -std=c++11 -lpthread
