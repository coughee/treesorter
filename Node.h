#ifndef NODE_H_INCLUDE
#define NODE_H_INCLUDE

class Node {
public:
  double x,y,z;
  double radius,length;
  double flow;
  long int parent, child1, child2;
  bool isEndNode;
  bool added;
  Node(){}
  Node(double x, double y, double z, double r, double l, int p,
       int c1, int c2, bool isEndNode);
  void print();
};
#endif
