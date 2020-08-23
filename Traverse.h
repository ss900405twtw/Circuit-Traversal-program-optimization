#ifndef _TRAVERSE_H
#define _TRAVERSE_H

#include "cirGate.h"

class TraverseStrategy
{
public:
   TraverseStrategy() {}
   ~TraverseStrategy() {}
   virtual void exec() = 0;
   void printGate() const
   {
  	  for(int i = 0; i < stateList.size(); ++i)
  	  {
  		  cout << stateList[i]->getID() << endl; 
  	  }
  	  // cout << endl;
    }

protected:
   vector<CirGate*> stateList;
   vector<CirGate*> PoList;
};
class DFS : public TraverseStrategy
{
public:
   DFS(vector<CirGate*> &poList) {PoList = poList;}
   ~DFS() {}
   void exec() override 
   {
  		for(int i = 0; i < PoList.size(); ++i)
  		{
  			DFSPo(PoList[i]->getFanin0Addr());
  			stateList.push_back(PoList[i]);
  		}
   }
   void DFSPo(CirGate *gate)
   {
	  	while(!gate->isVisited() && !gate)
	  	{
			if(gate->getTypeStr() != "Pi")
			{
		  		if(!gate->getFanin0Addr()->isVisited())
		    		DFSPo(gate->getFanin0Addr());
		  		if(!gate->getFanin1Addr()->isVisited())
		    		DFSPo(gate->getFanin1Addr());
			}
			gate->setState(1);
			stateList.push_back(gate);
	  	}
  }
};
#endif
