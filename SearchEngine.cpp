#include "SearchEngine.h"

SearchEngine::SearchEngine() : Matriks() {
	nbElmnt = 10;
	dataMatriks = new char*[nbElmnt];
	for (int idx = 0; idx < nbElmnt; idx++) {
		dataMatriks[idx] = new char[nbElmnt];
	}
	found = false;
	inputSearch = "";
}

SearchEngine::SearchEngine(int rowColumn) : Matriks(rowColumn) {
	found = false;
	inputSearch = "";
}

SearchEngine::SearchEngine(Matriks dataParser) : Matriks(dataParser){
	found = false;
	inputSearch = "";
}

SearchEngine::SearchEngine(Matriks dataParser, string input) : Matriks(dataParser){
	inputSearch = input;
	found = false;
}

SearchEngine::SearchEngine(const SearchEngine& searchSource) : Matriks(searchSource) {
	inputSearch = searchSource.inputSearch;
	found = false;
}

SearchEngine::~SearchEngine() {

}

SearchEngine& SearchEngine::operator=(const SearchEngine& searchSource) {
	for (int idx = 0; idx < nbElmnt; idx++) {
		delete [] dataMatriks[idx];
	}
	delete [] dataMatriks;

	dataMatriks = new char*[searchSource.nbElmnt];
	for (int idx = 0; idx < searchSource.nbElmnt; idx++) {
		dataMatriks[idx] = new char[searchSource.nbElmnt];
	}
	for (int idxRow = 0; idxRow < searchSource.nbElmnt; idxRow++) {
		for (int idxCol = 0; idxCol < searchSource.nbElmnt; idxCol++) {
			dataMatriks[idxRow][idxCol] = searchSource.dataMatriks[idxRow][idxCol];
		}
	}
	nbElmnt = searchSource.nbElmnt;

	inputSearch = searchSource.inputSearch;

	return *this;
}

string SearchEngine::getInputSearch() {
	return inputSearch;
}

void SearchEngine::setInputSearch(string input) {
	inputSearch = input;
}

bool SearchEngine::isFound() {
	return found;
}

void SearchEngine::searchRowTop(int startIdx) {
	int* fail = computeFail(inputSearch);

	int idxm = inputSearch.length();
	int idxSearch = startIdx;

	while (idxSearch < nbElmnt && !found) {
		int idxi = 0;
		int idxj = 0;
		while (idxi < nbElmnt && !found) {
			if  (inputSearch[idxj] == dataMatriks[idxSearch][idxi]) {
				if (idxj == idxm - 1) {
					found = true;
					cout << "RowTop" << endl;
				}
				idxi++;
				idxj++;
			}
			else if (idxj > 0) {
				idxj = fail[idxj-1];
			}
			else {
				idxi++;
			}
		}
		idxSearch++;
	}
}

void SearchEngine::searchRowDown(int startIdx) {
	int* fail = computeFail(inputSearch);

	int idxm = inputSearch.length();
	int idxSearch = startIdx;

	while (idxSearch < nbElmnt && !found) {
		int idxi = nbElmnt - 1;
		int idxj = 0;
		while (idxi >= 0 && !found) {
			if  (inputSearch[idxj] == dataMatriks[idxSearch][idxi]) {
				if (idxj == idxm - 1) {
					found = true;
					cout << "RowDown" << endl;
				}
				idxi--;
				idxj++;
			}
			else if (idxj > 0) {
				idxj = fail[idxj-1];
			}
			else {
				idxi--;
			}
		}
		idxSearch++;
	}
}

void SearchEngine::searchColTop(int startIdx) {
	int* fail = computeFail(inputSearch);

	int idxm = inputSearch.length();
	int idxSearch = startIdx;

	while (idxSearch < nbElmnt && !found) {
		int idxi = 0;
		int idxj = 0;
		while (idxi < nbElmnt && !found) {
			if  (inputSearch[idxj] == dataMatriks[idxi][idxSearch]) {
				if (idxj == idxm - 1) {
					found = true;
					cout << "ColTop" << endl;
				}
				idxi++;
				idxj++;
			}
			else if (idxj > 0) {
				idxj = fail[idxj-1];
			}
			else {
				idxi++;
			}
		}
		idxSearch++;
	}
}

void SearchEngine::searchColDown(int startIdx) {
	int* fail = computeFail(inputSearch);

	int idxm = inputSearch.length();
	int idxSearch = startIdx;

	while (idxSearch < nbElmnt && !found) {
		int idxi = nbElmnt - 1;
		int idxj = 0;
		while (idxi >= 0 && !found) {
			if  (inputSearch[idxj] == dataMatriks[idxi][idxSearch]) {
				if (idxj == idxm - 1) {
					found = true;
					cout << "ColDown" << endl;
				}
				idxi--;
				idxj++;
			}
			else if (idxj > 0) {
				idxj = fail[idxj-1];
			}
			else {
				idxi--;
			}
		}
		idxSearch++;
	}
}

void SearchEngine::searchDiagonalRTop(int startIdxRow, int startIdxCol) {

}

void SearchEngine::searchDiagonalRDown(int startIdxRow, int startIdxCol) {

}

void SearchEngine::searchDiagonalLTop(int startIdxRow, int startIdxCol) {

}

void SearchEngine::searchDiagonalLDown(int startIdxRow, int startIdxCol) {

}


int* SearchEngine::computeFail(string pattern) {
	int* fail = new int[pattern.length()];
	fail[0] = 0;

	int idxM = pattern.length();
	int idxj = 0;
	int idxi = 1;
	while (idxi < idxM) {
		if  (pattern[idxj] == pattern[idxi]) {
			fail[idxi] = idxj + 1;
			idxi++;
			idxj++;
		}
		else if (idxj > 0) {
			idxj = fail[idxj-1];
		}
		else {
			fail[idxi] = 0;
			idxi++;
		}
	}
	return fail;
}