#include "Matriks.h"

#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

class SearchEngine : public Matriks{
	public:
		//ctor, cctor, dtor, operator=
		SearchEngine();
		SearchEngine(int);
		SearchEngine(Matriks);
		SearchEngine(Matriks, string);
		SearchEngine(const SearchEngine&);
		~SearchEngine();
		SearchEngine& operator=(const SearchEngine&);
		
		//getter, setter
		string getInputSearch();
		void setInputSearch(string);
		bool isFound();

		//method
		void searchRowTop(int);
		void searchRowDown(int);
		void searchColTop(int);
		void searchColDown(int);
		void searchDiagonalRTop(int, int);
		void searchDiagonalRDown(int, int);
		void searchDiagonalLTop(int, int);
		void searchDiagonalLDown(int, int);
		int* computeFail(string);

	private:
		string inputSearch;
		bool found;
};

#endif