#ifndef CIR_GATE_H
#define CIR_GATE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;



class CirGate
{
public:
   CirGate() {}
   ~CirGate() {}

   // Basic access methods
   string getTypeStr() const {}
   int getID() const {return gateID;}


   // Printing functions
   virtual void printGate() const = 0;
   virtual CirGate* getFanin0Addr() const {}
   virtual CirGate* getFanin1Addr() const {}
   virtual int getFanin0() const {return -1;}
   virtual int getFanin1() const {return -1;}
   virtual void setf0(CirGate* addr) {}
   virtual void setf1(CirGate* addr) {}

   bool isVisited() const {return vis;}
   void setState(bool s) {vis = s;}

private:

protected:
  string gateType;
  int gateID;
  bool vis;

};

class PiGate : public CirGate
{
public:
   PiGate() {}
   PiGate(int id) 
   {
      gateType = "Pi";
      gateID = id;
      vis = 0;
   }
   ~PiGate() {}
   // Printing functions
   void printGate() const override
   {
      cout << "i'm Pi gate" << endl;
    }

private:

protected:
  

};

class PoGate : public CirGate
{
public:
   PoGate(){};
   PoGate(int fan, int id, bool inv):fanin0(fan),isInv(inv) 
   {
      gateType = "Po";
      gateID = id;
   }
   ~PoGate() {}
   // Printing functions
   void printGate() const override
   {
      cout << "i'm Po gate" << endl;
    }
   int getFanin0() const override {return fanin0;}
   CirGate* getFanin0Addr() const override {return fanin0Addr;}
   void setf0(CirGate* addr) override {fanin0Addr = addr;}

private:
  int fanin0;
  CirGate* fanin0Addr;
  int isInv;

protected:

};

class AndGate : public CirGate
{
public:
   AndGate(){};
   AndGate(int f0, int f1, int id, bool is0inv, bool is1inv)
   :fanin0(f0),fanin1(f1), is0Inv(is0inv), is1Inv(is1inv) 
   {
      gateType = "Po";
      gateID = id;
      vis = 0;
   }
   ~AndGate() {}
   // Printing functions
   void printGate() const override
   {
      cout << "i'm And gate" << endl;
    }
   int getFanin0() const override {return fanin0;}
   int getFanin1() const override {return fanin1;}
   CirGate* getFanin0Addr() const override {return fanin0Addr;}
   CirGate* getFanin1Addr() const override { return fanin1Addr;}
   void setf0(CirGate* addr) override {fanin0Addr = addr;}
   void setf1(CirGate* addr) override {fanin1Addr = addr;}

private:
  int fanin0,fanin1;
  CirGate *fanin0Addr,*fanin1Addr;
  int is0Inv,is1Inv;

protected:

};


#endif // CIR_GATE_H
