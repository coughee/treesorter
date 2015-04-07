#include "Node.h"

Node::Node(double x, double y, double z, double r, double l, int p,
	   int c1, int c2, bool isEndNode){
  this->x = x;
  this->y = y;
  this->z = z;

  this->r = r;
  this->l = l;
  
  this->p = p;
  this->c1 = c1;
  this->c2 = c2;
  
  this->isEndNode = isEndNode;
}
