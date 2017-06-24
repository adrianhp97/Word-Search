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

}

void SearchEngine::searchRowDown(int startIdx) {

}

void SearchEngine::searchColTop(int startIdx) {

}

void SearchEngine::searchColDown(int startIdx) {

}

void SearchEngine::searchDiagonalRTop(int startIdxRow, int startIdxCol) {

}

void SearchEngine::searchDiagonalRDown(int startIdxRow, int startIdxCol) {

}

void SearchEngine::searchDiagonalLTop(int startIdxRow, int startIdxCol) {

}

void SearchEngine::searchDiagonalLDown(int startIdxRow, int startIdxCol) {

}
