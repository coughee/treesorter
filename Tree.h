#ifndef TREE_H_INCLUDE
#define TREE_H_INCLUDE

#include "Node.h"
#include <vector>
#include <fstream>
#include <iostream>
class Tree {
public:
  double bifurcationExponent;
  double flow;

  bool isEndNode;
  
  std::vector<Node> nodes;
  
  Tree(){};
  void setRadii(int id);
  void setPositions(int id);
  void swap(int id1, int id2);
  void singleNodeSwap(int id1, int id2);
  int size();
  void readTree(char* filename);
  void writeTreeFile(char* outputname);
  void print();
};

#endif
