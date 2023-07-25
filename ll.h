#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "node.h"

class LL{
   nodePtr hol;
   int size;
  public:
     LL();
        void new_node(int, string);
	    void print_all();
     ~LL();

};

LL :: LL(){
  
  hol=NULL;
  size = 0;
}

LL::~LL(){
  
  nodePtr t=hol;
  
  while(hol){
    t=hol->get_next();
    delete hol;
    hol=t;
  }
}

void LL::new_node(int inp_id, string inp_name){
  if(hol==nullptr) 
    hol=new node(inp_id, inp_name);
  else{
    nodePtr t=hol;
    while(t->get_next()) 
      t=t->get_next();
      t->set_next(new node(inp_id, inp_name));
    }
  size ++;
}

void LL::print_all (){
  nodePtr t;
  for(t=hol; t; t=t->get_next())
    t->print();
}