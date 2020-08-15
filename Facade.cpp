#include "Facade.h"
#include "cirGate.h"
using namespace std;

void FacadeMgr::readGate(const char* f)
{
	ifstream file; 
	file.open(f, ios::in);
	if(!file)
	{
		cerr << "Can't open file!\n";
		exit(1);
	}
	else
	{
		string line;
		int id;
	    getline(file, line);
	  	istringstream iss(line);
		iss >> name >> M >> I >> L >> O >> A;
		id = M+1;
	    for(int i = 0; i < I ; ++i)
	    {
	    	getline(file, line);
	    	CirGate* pi = new PiGate(stoi(line)/2);
	    	PiList.push_back(pi);
		}
	    for(int i = 0; i < O ; ++i)
	    {
	    	getline(file, line);
	    	int tok = stoi(line);
	    	bool isInv;
	    	tok % 2 == 0 ? isInv = 0: isInv = 1;
	    	CirGate* po = new PoGate(tok/2, id,isInv);
	    	PoList.push_back(po);
	    	id++;
		}
	    for(int i = 0; i < A ; ++i)
	    {
	    	getline(file, line);
	    	istringstream iss(line);
	    	int id,l1,l2;
	    	iss >> id >> l1 >> l2;
	    	bool is0Inv;
	    	l1 % 2 == 0 ? is0Inv = 0: is0Inv = 1;
	    	bool is1Inv;
	    	l2 % 2 == 0 ? is1Inv = 0: is1Inv = 1;
	    	CirGate* aig = new AndGate(l1/2, l2/2, id/2, is0Inv, is1Inv);
	    	AigList.push_back(aig);
		}
}
	file.close();
}
void FacadeMgr::ConnectCir()
{
	//connect Output gate
	for(int i = 0; i < PoList.size(); ++i)
	{
		PoList[i]->setf0(findGate(PoList[i]->getFanin0()));
	}
	// connect And Gate
	for(int i = 0; i < AigList.size(); ++i)
	{
		AigList[i]->setf0(findGate(AigList[i]->getFanin0()));
		AigList[i]->setf1(findGate(AigList[i]->getFanin1()));
	}
}
CirGate* FacadeMgr::findGate (int id) const
{
	for(int i = 0; i < GateList.size(); ++i)
	{
		if(GateList[i]->getID() == id) return GateList[i];
	}
	//can't find the gate
	return NULL;
}
void FacadeMgr::printGate()
{
	//Using DFS algorithm to print the gate (delegateion)
	st = new DFS(PoList);
	st->exec();
	st->printGate();
}
void FacadeMgr::recycleMemory()
{
	//recycle the allocated memory
	for(int i = 0; i < GateList.size(); ++i) delete GateList[i];
}

