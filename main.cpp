#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Facade.h"
using namespace std;


int main(int argc, char** argv)
{
	FacadeMgr* s1 = new FacadeMgr;
	s1->readGate(argv[1]);
	s1->ConnectCir();
	s1->printGate();
	s1->recycleMemory();
	delete s1;

	return 0;
}