#ifndef FACADE_H
#define FACADE_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "cirGate.h"
#include "Traverse.h"
using namespace std;


class FacadeMgr
{

public:
	//parsing the circuit
	void readGate(const char* f);
	//connect the circuit
	void ConnectCir();
	// ind the gate address by gate ID
	CirGate* findGate (int id) const;
	//print the whole gate
	void printGate();
	//recyle the whole allocated memory
	void recycleMemory();

private:
	//file name
	string name;
	int M,I,L,O,A;
	//store the whole gate
	vector<CirGate*> GateList;
	//store only input gate
	vector<CirGate*> PiList;
	//store only output gate
	vector<CirGate*> PoList;
	//store only and gate
	vector<CirGate*> AigList;
	//hole the strategy's referencr
	TraverseStrategy* st;
};
#endif // FACADE_H

