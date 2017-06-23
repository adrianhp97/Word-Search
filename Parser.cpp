#include "Parser.h"

Parser::Parser() {
	file.open("data.txt");

	string dummyElmnnt;
	file >> dummyElmnnt;
	Matriks dummyMatriks(dummyElmnnt.length());
	data = dummyMatriks;

	file.seekg(0, ios::beg);
	for (int idxRow = 0; idxRow < data.getNbElmnt(); idxRow++) {
		string line;
		file >> line;
		for (int idxCol = 0; idxCol < data.getNbElmnt(); idxCol++) {
			data.setDataAt(idxRow, idxCol, line[idxCol]);
		}
	}

	file.close();
}

Matriks Parser::getMatriks() {
	return data;
}