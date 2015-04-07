#ifndef NODE_H_INCLUDE
#define NODE_H_INCLUDE
class Node {
  double x,y,z;
  double r,l;
  int p, c1, c2;
  bool isEndNode;

  Node(double x, double y, double z, double r, double l, int p,
       int c1, int c2, bool isEndNode);
};
#endif
