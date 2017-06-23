#include <iostream>

using namespace std;

#ifndef MATRIKS_H
#define MATRIKS_H

class Matriks {
	public:
		Matriks();
		Matriks(int);
		Matriks(const Matriks&);
		~Matriks();
		Matriks& operator=(const Matriks&);
		void printMatriks();
		int getNbElmnt();
		char getDataAt(int, int);
		void setNbElmnt(int);
		void setDataAt(int, int, int);

	private:
		char** dataMatriks;
		int nbElmnt;
};

#endif