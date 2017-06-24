#include "Parser.h"

Parser::Parser() : Matriks() {
	try{
		file.open("data.txt");
		
		string dummyElmnnt;
		file >> dummyElmnnt;

		dataMatriks = new char*[dummyElmnnt.length()];
		for (int idx = 0; idx < dummyElmnnt.length(); idx++) {
			dataMatriks[idx] = new char[dummyElmnnt.length()];
		}
		nbElmnt = dummyElmnnt.length();
		
		file.seekg(0, ios::beg);
		for (int idxRow = 0; idxRow < nbElmnt; idxRow++) {
			string line;
			file >> line;
			for (int idxCol = 0; idxCol < nbElmnt; idxCol++) {
				dataMatriks[idxRow][idxCol] =  line[idxCol];
			}
		}

		file.close();
	} catch(int e) {

	}
}