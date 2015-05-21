#include "Node.h"
#include <iostream>
using namespace std;
Node::Node(double x, double y, double z, double r, double l, int p,
	   int c1, int c2, bool isEndNode){
  this->x = x;
  this->y = y;
  this->z = z;

  this->radius = r;
  this->length = l;
  
  this->parent = p;
  this->child1 = c1;
  this->child2 = c2;
  
  this->isEndNode = isEndNode;
}

void Node::print(){
  cout << parent << "\t" << child1 << "\t" << child2 << "\t" << isEndNode << "\n";
}
