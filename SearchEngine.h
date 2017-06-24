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


	private:
		string inputSearch;
		bool found;
};

#endif