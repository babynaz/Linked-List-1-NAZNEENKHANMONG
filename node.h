#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class node{
private:
    int id;
	  string name; 
    node* next;
 public:

    node(int,string);
    void print();
    node* get_next(){return next;}
    void set_next(node*);
    string get_name() {return name;}
    int get_id() {return id;}
    ~node() {cout<<name<<" deleted\n";}

};

typedef node* nodePtr;

void node :: print(){
  
  cout<<"ID : "<<id<<" Name : "<<name<<"\n";
}

node :: node(int inp_id, string inp_name){
  
  id = inp_id;
  name = inp_name;
}

void node :: set_next(node* inp_next){
  
  next = inp_next;
}